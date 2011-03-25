/* side_panel.c generated by valac 0.10.3, the Vala compiler
 * generated from side_panel.vala, do not modify */

/*
 * This file is part of LaTeXila.
 *
 * Copyright © 2010 Sébastien Wilmet
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

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <glib/gi18n-lib.h>


#define TYPE_SIDE_PANEL (side_panel_get_type ())
#define SIDE_PANEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SIDE_PANEL, SidePanel))
#define SIDE_PANEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SIDE_PANEL, SidePanelClass))
#define IS_SIDE_PANEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SIDE_PANEL))
#define IS_SIDE_PANEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SIDE_PANEL))
#define SIDE_PANEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SIDE_PANEL, SidePanelClass))

typedef struct _SidePanel SidePanel;
typedef struct _SidePanelClass SidePanelClass;
typedef struct _SidePanelPrivate SidePanelPrivate;

#define TYPE_MAIN_WINDOW (main_window_get_type ())
#define MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MAIN_WINDOW, MainWindow))
#define MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MAIN_WINDOW, MainWindowClass))
#define IS_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MAIN_WINDOW))
#define IS_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MAIN_WINDOW))
#define MAIN_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MAIN_WINDOW, MainWindowClass))

typedef struct _MainWindow MainWindow;
typedef struct _MainWindowClass MainWindowClass;

#define SIDE_PANEL_TYPE_SIDE_PANEL_COLUMN (side_panel_side_panel_column_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block12Data Block12Data;

struct _SidePanel {
	GtkVBox parent_instance;
	SidePanelPrivate * priv;
};

struct _SidePanelClass {
	GtkVBoxClass parent_class;
};

struct _SidePanelPrivate {
	MainWindow* main_window;
	GtkToggleAction* action_view_side_panel;
	GtkVBox** components;
	gint components_length1;
	gint _components_size_;
	GtkComboBox* combo_box;
	GtkListStore* list_store;
};

typedef enum  {
	SIDE_PANEL_SIDE_PANEL_COLUMN_PIXBUF,
	SIDE_PANEL_SIDE_PANEL_COLUMN_NAME,
	SIDE_PANEL_SIDE_PANEL_COLUMN_N_COLUMNS
} SidePanelSidePanelColumn;

struct _Block12Data {
	int _ref_count_;
	SidePanel * self;
	GtkComboBox* combo_box;
};


static gpointer side_panel_parent_class = NULL;

GType side_panel_get_type (void) G_GNUC_CONST;
GType main_window_get_type (void) G_GNUC_CONST;
#define SIDE_PANEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_SIDE_PANEL, SidePanelPrivate))
enum  {
	SIDE_PANEL_DUMMY_PROPERTY
};
static GType side_panel_side_panel_column_get_type (void) G_GNUC_UNUSED;
SidePanel* side_panel_new (MainWindow* main_window, GtkToggleAction* action_view_side_panel);
SidePanel* side_panel_construct (GType object_type, MainWindow* main_window, GtkToggleAction* action_view_side_panel);
static GtkComboBox* side_panel_get_combo_box (SidePanel* self);
static GtkButton* side_panel_get_close_button (SidePanel* self);
void side_panel_add_component (SidePanel* self, const char* name, const char* stock_id, GtkVBox* component);
static void _vala_array_add15 (GtkVBox*** array, int* length, int* size, GtkVBox* value);
void side_panel_restore_state (SidePanel* self);
static void _lambda47_ (SidePanel* self);
static void __lambda47__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void _lambda46_ (Block12Data* _data12_);
static void __lambda46__gtk_combo_box_changed (GtkComboBox* _sender, gpointer self);
static Block12Data* block12_data_ref (Block12Data* _data12_);
static void block12_data_unref (Block12Data* _data12_);
gint side_panel_get_active_component (SidePanel* self);
static void side_panel_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



static GType side_panel_side_panel_column_get_type (void) {
	static volatile gsize side_panel_side_panel_column_type_id__volatile = 0;
	if (g_once_init_enter (&side_panel_side_panel_column_type_id__volatile)) {
		static const GEnumValue values[] = {{SIDE_PANEL_SIDE_PANEL_COLUMN_PIXBUF, "SIDE_PANEL_SIDE_PANEL_COLUMN_PIXBUF", "pixbuf"}, {SIDE_PANEL_SIDE_PANEL_COLUMN_NAME, "SIDE_PANEL_SIDE_PANEL_COLUMN_NAME", "name"}, {SIDE_PANEL_SIDE_PANEL_COLUMN_N_COLUMNS, "SIDE_PANEL_SIDE_PANEL_COLUMN_N_COLUMNS", "n-columns"}, {0, NULL, NULL}};
		GType side_panel_side_panel_column_type_id;
		side_panel_side_panel_column_type_id = g_enum_register_static ("SidePanelSidePanelColumn", values);
		g_once_init_leave (&side_panel_side_panel_column_type_id__volatile, side_panel_side_panel_column_type_id);
	}
	return side_panel_side_panel_column_type_id__volatile;
}


SidePanel* side_panel_construct (GType object_type, MainWindow* main_window, GtkToggleAction* action_view_side_panel) {
	SidePanel * self;
	GtkHBox* hbox;
	GtkComboBox* _tmp0_;
	GtkButton* _tmp1_;
	g_return_val_if_fail (main_window != NULL, NULL);
	g_return_val_if_fail (action_view_side_panel != NULL, NULL);
	self = g_object_newv (object_type, 0, NULL);
	self->priv->main_window = main_window;
	self->priv->action_view_side_panel = action_view_side_panel;
	hbox = g_object_ref_sink ((GtkHBox*) gtk_hbox_new (FALSE, 3));
	gtk_container_set_border_width ((GtkContainer*) hbox, (guint) 3);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) hbox, FALSE, FALSE, (guint) 3);
	self->priv->combo_box = (_tmp0_ = side_panel_get_combo_box (self), _g_object_unref0 (self->priv->combo_box), _tmp0_);
	gtk_box_pack_start ((GtkBox*) hbox, (GtkWidget*) self->priv->combo_box, TRUE, TRUE, 0);
	gtk_box_pack_start ((GtkBox*) hbox, (GtkWidget*) (_tmp1_ = side_panel_get_close_button (self)), FALSE, FALSE, 0);
	_g_object_unref0 (_tmp1_);
	gtk_widget_show_all ((GtkWidget*) self);
	_g_object_unref0 (hbox);
	return self;
}


SidePanel* side_panel_new (MainWindow* main_window, GtkToggleAction* action_view_side_panel) {
	return side_panel_construct (TYPE_SIDE_PANEL, main_window, action_view_side_panel);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _vala_array_add15 (GtkVBox*** array, int* length, int* size, GtkVBox* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (GtkVBox*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


void side_panel_add_component (SidePanel* self, const char* name, const char* stock_id, GtkVBox* component) {
	GtkTreeIter iter = {0};
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (stock_id != NULL);
	g_return_if_fail (component != NULL);
	gtk_list_store_append (self->priv->list_store, &iter);
	gtk_list_store_set (self->priv->list_store, &iter, SIDE_PANEL_SIDE_PANEL_COLUMN_PIXBUF, stock_id, SIDE_PANEL_SIDE_PANEL_COLUMN_NAME, name, -1, -1);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) component, TRUE, TRUE, 0);
	_vala_array_add15 (&self->priv->components, &self->priv->components_length1, &self->priv->_components_size_, _g_object_ref0 (component));
}


void side_panel_restore_state (SidePanel* self) {
	GSettings* settings;
	gint num;
	g_return_if_fail (self != NULL);
	settings = g_settings_new ("org.gnome.latexila.preferences.ui");
	num = g_settings_get_int (settings, "side-panel-component");
	num = CLAMP (num, 0, self->priv->components_length1 - 1);
	gtk_combo_box_set_active (self->priv->combo_box, num);
	_g_object_unref0 (settings);
}


static void _lambda47_ (SidePanel* self) {
	gtk_widget_hide ((GtkWidget*) self);
	gtk_toggle_action_set_active (self->priv->action_view_side_panel, FALSE);
}


static void __lambda47__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	_lambda47_ (self);
}


static GtkButton* side_panel_get_close_button (SidePanel* self) {
	GtkButton* result = NULL;
	GtkButton* close_button;
	GtkImage* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	close_button = g_object_ref_sink ((GtkButton*) gtk_button_new ());
	gtk_button_set_relief (close_button, GTK_RELIEF_NONE);
	gtk_button_set_focus_on_click (close_button, FALSE);
	gtk_widget_set_tooltip_text ((GtkWidget*) close_button, _ ("Hide panel"));
	gtk_container_add ((GtkContainer*) close_button, (GtkWidget*) (_tmp0_ = g_object_ref_sink ((GtkImage*) gtk_image_new_from_stock (GTK_STOCK_CLOSE, GTK_ICON_SIZE_MENU))));
	_g_object_unref0 (_tmp0_);
	g_signal_connect_object (close_button, "clicked", (GCallback) __lambda47__gtk_button_clicked, self, 0);
	result = close_button;
	return result;
}


static void _lambda46_ (Block12Data* _data12_) {
	SidePanel * self;
	gint i;
	self = _data12_->self;
	{
		GtkVBox** component_collection;
		int component_collection_length1;
		int component_it;
		component_collection = self->priv->components;
		component_collection_length1 = self->priv->components_length1;
		for (component_it = 0; component_it < self->priv->components_length1; component_it = component_it + 1) {
			GtkVBox* component;
			component = _g_object_ref0 (component_collection[component_it]);
			{
				gtk_widget_hide ((GtkWidget*) component);
				_g_object_unref0 (component);
			}
		}
	}
	i = gtk_combo_box_get_active (_data12_->combo_box);
	gtk_widget_show ((GtkWidget*) self->priv->components[i]);
}


static void __lambda46__gtk_combo_box_changed (GtkComboBox* _sender, gpointer self) {
	_lambda46_ (self);
}


static Block12Data* block12_data_ref (Block12Data* _data12_) {
	g_atomic_int_inc (&_data12_->_ref_count_);
	return _data12_;
}


static void block12_data_unref (Block12Data* _data12_) {
	if (g_atomic_int_dec_and_test (&_data12_->_ref_count_)) {
		_g_object_unref0 (_data12_->self);
		_g_object_unref0 (_data12_->combo_box);
		g_slice_free (Block12Data, _data12_);
	}
}


static GtkComboBox* side_panel_get_combo_box (SidePanel* self) {
	GtkComboBox* result = NULL;
	Block12Data* _data12_;
	GtkListStore* _tmp0_;
	GtkCellRendererPixbuf* pixbuf_renderer;
	GtkCellRendererText* text_renderer;
	g_return_val_if_fail (self != NULL, NULL);
	_data12_ = g_slice_new0 (Block12Data);
	_data12_->_ref_count_ = 1;
	_data12_->self = g_object_ref (self);
	self->priv->list_store = (_tmp0_ = gtk_list_store_new ((gint) SIDE_PANEL_SIDE_PANEL_COLUMN_N_COLUMNS, G_TYPE_STRING, G_TYPE_STRING), _g_object_unref0 (self->priv->list_store), _tmp0_);
	_data12_->combo_box = g_object_ref_sink ((GtkComboBox*) gtk_combo_box_new_with_model ((GtkTreeModel*) self->priv->list_store));
	pixbuf_renderer = g_object_ref_sink ((GtkCellRendererPixbuf*) gtk_cell_renderer_pixbuf_new ());
	gtk_cell_layout_pack_start ((GtkCellLayout*) _data12_->combo_box, (GtkCellRenderer*) pixbuf_renderer, FALSE);
	gtk_cell_layout_set_attributes ((GtkCellLayout*) _data12_->combo_box, (GtkCellRenderer*) pixbuf_renderer, "stock-id", SIDE_PANEL_SIDE_PANEL_COLUMN_PIXBUF, NULL, NULL);
	text_renderer = g_object_ref_sink ((GtkCellRendererText*) gtk_cell_renderer_text_new ());
	gtk_cell_layout_pack_start ((GtkCellLayout*) _data12_->combo_box, (GtkCellRenderer*) text_renderer, TRUE);
	gtk_cell_layout_set_attributes ((GtkCellLayout*) _data12_->combo_box, (GtkCellRenderer*) text_renderer, "text", SIDE_PANEL_SIDE_PANEL_COLUMN_NAME, NULL, NULL);
	g_signal_connect_data (_data12_->combo_box, "changed", (GCallback) __lambda46__gtk_combo_box_changed, block12_data_ref (_data12_), (GClosureNotify) block12_data_unref, 0);
	result = _g_object_ref0 (_data12_->combo_box);
	_g_object_unref0 (text_renderer);
	_g_object_unref0 (pixbuf_renderer);
	block12_data_unref (_data12_);
	return result;
}


gint side_panel_get_active_component (SidePanel* self) {
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	result = gtk_combo_box_get_active (self->priv->combo_box);
	return result;
}


static void side_panel_class_init (SidePanelClass * klass) {
	side_panel_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SidePanelPrivate));
	G_OBJECT_CLASS (klass)->finalize = side_panel_finalize;
}


static void side_panel_instance_init (SidePanel * self) {
	self->priv = SIDE_PANEL_GET_PRIVATE (self);
}


static void side_panel_finalize (GObject* obj) {
	SidePanel * self;
	self = SIDE_PANEL (obj);
	self->priv->components = (_vala_array_free (self->priv->components, self->priv->components_length1, (GDestroyNotify) g_object_unref), NULL);
	_g_object_unref0 (self->priv->combo_box);
	_g_object_unref0 (self->priv->list_store);
	G_OBJECT_CLASS (side_panel_parent_class)->finalize (obj);
}


GType side_panel_get_type (void) {
	static volatile gsize side_panel_type_id__volatile = 0;
	if (g_once_init_enter (&side_panel_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SidePanelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) side_panel_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SidePanel), 0, (GInstanceInitFunc) side_panel_instance_init, NULL };
		GType side_panel_type_id;
		side_panel_type_id = g_type_register_static (GTK_TYPE_VBOX, "SidePanel", &g_define_type_info, 0);
		g_once_init_leave (&side_panel_type_id__volatile, side_panel_type_id);
	}
	return side_panel_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



