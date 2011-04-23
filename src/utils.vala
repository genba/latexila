/*
 * This file is part of LaTeXila.
 *
 * Copyright © 2010-2011 Sébastien Wilmet
 *
 * LaTeXila is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LaTeXila is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LaTeXila.  If not, see <http://www.gnu.org/licenses/>.
 */

using Gtk;

namespace Utils
{
    public void flush_queue ()
    {
        while (Gtk.events_pending ())
            Gtk.main_iteration ();
    }

    public string str_middle_truncate (string str, uint max_length)
    {
        if (str.length <= max_length)
            return str;

        var half_length = (max_length - 4) / 2;
        var l = str.length;
        return str[0:half_length] + "..." + str[l-half_length:l];
    }

    public string replace_home_dir_with_tilde (string uri)
    {
        return_val_if_fail (uri != null, null);
        string home = Environment.get_home_dir ();
        if (uri == home)
            return "~";
        if (uri.has_prefix (home))
            return "~" + uri[home.length:uri.length];
        return uri;
    }

    public string? uri_get_dirname (string uri)
    {
        return_val_if_fail (uri != null, null);
        string dir = Path.get_dirname (uri);
        if (dir == ".")
            return null;
        return replace_home_dir_with_tilde (dir);
    }

    /* Returns a string suitable to be displayed in the UI indicating
     * the name of the directory where the file is located.
     * For remote files it may also contain the hostname etc.
     * For local files it tries to replace the home dir with ~.
     */
    public string? get_dirname_for_display (File location)
    {
        try
        {
            Mount mount = location.find_enclosing_mount (null);
            string mount_name = mount.get_name ();
            var dirname = uri_get_dirname (location.get_path () ?? location.get_uri ());

            if (dirname == null || dirname == ".")
                return mount_name;
            return mount_name + " " + dirname;
        }

        // local files or uri without mounts
        catch (Error e)
        {
            return uri_get_dirname (location.get_path () ?? location.get_uri ());
        }
    }

    // get filename without extension (without the dot)
    public string get_shortname (string path)
    {
        return path[0:get_extension_pos (path)];
    }

    // get file's extension (with the dot)
    public string get_extension (string path)
    {
        return path[get_extension_pos (path):path.length].down ();
    }

    private long get_extension_pos (string path)
    {
        long l = path.length;

        for (long i = l - 1 ; i >= 0 ; i--)
        {
            if (path[i] == '/')
                return l;
            else if (path[i] == '.')
                return i;
        }

        return l;
    }

    public const uint ALL_WORKSPACES = 0xffffff;

    /* Get the workspace the window is on
     *
     * This function gets the workspace that the #GtkWindow is visible on,
     * it returns ALL_WORKSPACES if the window is sticky, or if
     * the window manager doesn't support this function.
     */
    public uint get_window_workspace (Gtk.Window gtkwindow)
    {
        return_val_if_fail (gtkwindow.get_realized (), 0);

        uint ret = ALL_WORKSPACES;

        Gdk.Window window = gtkwindow.get_window ();
        Gdk.Display display = window.get_display ();
        unowned X.Display x_display = Gdk.x11_display_get_xdisplay (display);

        X.Atom type;
        int format;
        ulong nitems;
        ulong bytes_after;
        uint *workspace;

        Gdk.error_trap_push ();

        int result = x_display.get_window_property (Gdk.x11_drawable_get_xid (window),
            Gdk.x11_get_xatom_by_name_for_display (display, "_NET_WM_DESKTOP"),
            0, long.MAX, false, X.XA_CARDINAL, out type, out format, out nitems,
            out bytes_after, out workspace);

        int err = Gdk.error_trap_pop ();

        if (err != X.Success || result != X.Success)
            return ret;

        if (type == X.XA_CARDINAL && format == 32 && nitems > 0)
            ret = workspace[0];

        X.free (workspace);
        return ret;
    }

    public Widget add_scrollbar (Widget child)
    {
        var scrollbar = new ScrolledWindow (null, null);
        scrollbar.set_policy (PolicyType.AUTOMATIC, PolicyType.AUTOMATIC);
        scrollbar.add (child);
        return scrollbar;
    }

    public void print_build_tool (BuildTool build_tool)
    {
        stdout.printf ("\n=== Build Tool ===\n");
        stdout.printf ("desc: %s\n", build_tool.description);
        stdout.printf ("ext: %s\n", build_tool.extensions);
        stdout.printf ("label: %s\n", build_tool.label);
        stdout.printf ("icon: %s\n\n", build_tool.icon);

        foreach (BuildJob build_job in build_tool.jobs)
        {
            stdout.printf ("== Build Job ==\n");
            stdout.printf ("must succeed: %s\n", build_job.must_succeed.to_string ());
            stdout.printf ("post processor: %s\n", build_job.post_processor);
            stdout.printf ("command: %s\n\n", build_job.command);
        }
    }

    public void delete_file (File file)
    {
        try
        {
            file.delete ();
        }
        catch (Error e)
        {
            stderr.printf ("Warning: delete file \"%s\" failed: %s\n",
                file.get_parse_name (), e.message);
        }
    }

    public bool tree_model_iter_prev (TreeModel model, ref TreeIter iter)
    {
        TreePath path = model.get_path (iter);
        if (path.prev ())
        {
            bool ret = model.get_iter (out iter, path);
            return ret;
        }
        return false;
    }

    public void set_entry_error (Widget entry, bool error)
    {
        if (error)
        {
            Gdk.Color red, white;
            Gdk.Color.parse ("#FF6666", out red);
            Gdk.Color.parse ("white", out white);
            entry.modify_base (StateType.NORMAL, red);
            entry.modify_text (StateType.NORMAL, white);
        }
        else
        {
            entry.modify_base (StateType.NORMAL, null);
            entry.modify_text (StateType.NORMAL, null);
        }
    }

    // get indice of selected row in the treeview
    // returns -1 if no row is selected
    public int get_selected_row (TreeView view, out TreeIter iter_to_set = null)
    {
        TreeSelection select = view.get_selection ();
        TreeIter iter;
        if (select.get_selected (null, out iter))
        {
            if (&iter_to_set != null)
                iter_to_set = iter;
            TreeModel model = view.get_model ();
            TreePath path = model.get_path (iter);
            return path.get_indices ()[0];
        }
        return -1;
    }

    public Gdk.Pixbuf get_pixbuf_from_stock (string stock_id, Gtk.IconSize size)
    {
        var w = new Gtk.Invisible ();
        var pixbuf = w.render_icon (stock_id, size, "vala");
        return pixbuf;
    }

    public Button get_toolbar_button (string stock_id)
    {
        return _get_toolbar_button_impl (stock_id, false);
    }

    public ToggleButton get_toolbar_toggle_button (string stock_id)
    {
        return (ToggleButton) _get_toolbar_button_impl (stock_id, true);
    }

    private Button _get_toolbar_button_impl (string stock_id, bool toggle)
    {
        Button button;
        if (toggle)
            button = new ToggleButton ();
        else
            button = new Button ();

        Image image = new Image.from_stock (stock_id, IconSize.MENU);
        button.add (image);
        button.set_relief (ReliefStyle.NONE);
        return button;
    }

    public bool char_is_escaped (string text, long index)
    {
        bool escaped = false;
        for (long i = index - 1 ; i >= 0 ; i--)
        {
            if (text[i] == '\\')
                escaped = ! escaped;
            else
                break;
        }
        return escaped;
    }
}
