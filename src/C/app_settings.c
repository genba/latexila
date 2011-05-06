/* app_settings.c generated by valac 0.12.0, the Vala compiler
 * generated from app_settings.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <config.h>
#include <gtksourceview/gtksourcestyleschememanager.h>
#include <gtksourceview/gtksourceview.h>
#include <gtk/gtk.h>


#define TYPE_APP_SETTINGS (app_settings_get_type ())
#define APP_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_APP_SETTINGS, AppSettings))
#define APP_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_APP_SETTINGS, AppSettingsClass))
#define IS_APP_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_APP_SETTINGS))
#define IS_APP_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_APP_SETTINGS))
#define APP_SETTINGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_APP_SETTINGS, AppSettingsClass))

typedef struct _AppSettings AppSettings;
typedef struct _AppSettingsClass AppSettingsClass;
typedef struct _AppSettingsPrivate AppSettingsPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_APPLICATION (application_get_type ())
#define APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_APPLICATION, Application))
#define APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_APPLICATION, ApplicationClass))
#define IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_APPLICATION))
#define IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_APPLICATION))
#define APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_APPLICATION, ApplicationClass))

typedef struct _Application Application;
typedef struct _ApplicationClass ApplicationClass;

#define TYPE_DOCUMENT (document_get_type ())
#define DOCUMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DOCUMENT, Document))
#define DOCUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DOCUMENT, DocumentClass))
#define IS_DOCUMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DOCUMENT))
#define IS_DOCUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DOCUMENT))
#define DOCUMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DOCUMENT, DocumentClass))

typedef struct _Document Document;
typedef struct _DocumentClass DocumentClass;
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))

#define TYPE_DOCUMENT_VIEW (document_view_get_type ())
#define DOCUMENT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DOCUMENT_VIEW, DocumentView))
#define DOCUMENT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DOCUMENT_VIEW, DocumentViewClass))
#define IS_DOCUMENT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DOCUMENT_VIEW))
#define IS_DOCUMENT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DOCUMENT_VIEW))
#define DOCUMENT_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DOCUMENT_VIEW, DocumentViewClass))

typedef struct _DocumentView DocumentView;
typedef struct _DocumentViewClass DocumentViewClass;
typedef struct _DocumentPrivate DocumentPrivate;

#define TYPE_DOCUMENT_TAB (document_tab_get_type ())
#define DOCUMENT_TAB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DOCUMENT_TAB, DocumentTab))
#define DOCUMENT_TAB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DOCUMENT_TAB, DocumentTabClass))
#define IS_DOCUMENT_TAB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DOCUMENT_TAB))
#define IS_DOCUMENT_TAB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DOCUMENT_TAB))
#define DOCUMENT_TAB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DOCUMENT_TAB, DocumentTabClass))

typedef struct _DocumentTab DocumentTab;
typedef struct _DocumentTabClass DocumentTabClass;

struct _AppSettings {
	GSettings parent_instance;
	AppSettingsPrivate * priv;
};

struct _AppSettingsClass {
	GSettingsClass parent_class;
};

struct _AppSettingsPrivate {
	GSettings* editor;
	GSettings* desktop_interface;
	guint timeout_id;
	gchar* _system_font;
};

struct _Document {
	GtkSourceBuffer parent_instance;
	DocumentPrivate * priv;
	DocumentTab* tab;
	guint _unsaved_doc_num;
};

struct _DocumentClass {
	GtkSourceBufferClass parent_class;
};


static gpointer app_settings_parent_class = NULL;
static AppSettings* app_settings_instance;
static AppSettings* app_settings_instance = NULL;

GType app_settings_get_type (void) G_GNUC_CONST;
#define APP_SETTINGS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_APP_SETTINGS, AppSettingsPrivate))
enum  {
	APP_SETTINGS_DUMMY_PROPERTY,
	APP_SETTINGS_SYSTEM_FONT
};
static AppSettings* app_settings_new (void);
static AppSettings* app_settings_construct (GType object_type);
static void app_settings_initialize (AppSettings* self);
AppSettings* app_settings_get_default (void);
static void app_settings_set_system_font (AppSettings* self, const gchar* value);
static void _lambda3_ (GSettings* setting, const gchar* key, AppSettings* self);
static void app_settings_set_font (AppSettings* self, const gchar* font);
const gchar* app_settings_get_system_font (AppSettings* self);
static void __lambda3__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda87_ (GSettings* setting, const gchar* key, AppSettings* self);
static void __lambda87__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda88_ (GSettings* setting, const gchar* key, AppSettings* self);
static void __lambda88__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda89_ (GSettings* setting, const gchar* key, AppSettings* self);
GType application_get_type (void) G_GNUC_CONST;
Application* application_get_default (void);
GType document_get_type (void) G_GNUC_CONST;
GList* application_get_documents (Application* self);
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
static void __lambda89__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda90_ (GSettings* setting, const gchar* key, AppSettings* self);
GType document_view_get_type (void) G_GNUC_CONST;
GList* application_get_views (Application* self);
static void __lambda90__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda91_ (GSettings* setting, const gchar* key, AppSettings* self);
static void __lambda91__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda92_ (GSettings* setting, const gchar* key, AppSettings* self);
static void __lambda92__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda93_ (GSettings* setting, const gchar* key, AppSettings* self);
static void __lambda93__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda94_ (GSettings* setting, const gchar* key, AppSettings* self);
static void __lambda94__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda95_ (GSettings* setting, const gchar* key, AppSettings* self);
GType document_tab_get_type (void) G_GNUC_CONST;
void document_tab_set_auto_save (DocumentTab* self, gboolean value);
static void __lambda95__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda96_ (GSettings* setting, const gchar* key, AppSettings* self);
void document_tab_set_auto_save_interval (DocumentTab* self, guint value);
static void __lambda96__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static void _lambda97_ (GSettings* setting, const gchar* key, AppSettings* self);
static gboolean _lambda98_ (AppSettings* self);
void symbols_reload_most_used_symbols (void);
static gboolean __lambda98__gsource_func (gpointer self);
static void __lambda97__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
void document_view_set_font_from_string (DocumentView* self, const gchar* font);
static void app_settings_finalize (GObject* obj);
static void _vala_app_settings_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_app_settings_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static AppSettings* app_settings_construct (GType object_type) {
	AppSettings * self = NULL;
	self = (AppSettings*) g_object_new (object_type, "schema", "org.gnome.latexila", NULL);
	app_settings_initialize (self);
	return self;
}


static AppSettings* app_settings_new (void) {
	return app_settings_construct (TYPE_APP_SETTINGS);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


AppSettings* app_settings_get_default (void) {
	AppSettings* result = NULL;
	AppSettings* _tmp1_;
	if (app_settings_instance == NULL) {
		AppSettings* _tmp0_ = NULL;
		_tmp0_ = app_settings_new ();
		_g_object_unref0 (app_settings_instance);
		app_settings_instance = _tmp0_;
	}
	_tmp1_ = _g_object_ref0 (app_settings_instance);
	result = _tmp1_;
	return result;
}


static void _lambda3_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	gboolean _tmp2_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_string (setting, key);
	_tmp1_ = _tmp0_;
	app_settings_set_system_font (self, _tmp1_);
	_g_free0 (_tmp1_);
	_tmp2_ = g_settings_get_boolean (self->priv->editor, "use-default-font");
	if (_tmp2_) {
		app_settings_set_font (self, self->priv->_system_font);
	}
}


static void __lambda3__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda3_ (_sender, key, self);
}


static void _lambda87_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gboolean _tmp0_;
	gboolean val;
	gchar* _tmp1_ = NULL;
	gchar* _tmp4_;
	gchar* font;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_boolean (setting, key);
	val = _tmp0_;
	if (val) {
		gchar* _tmp2_;
		_tmp2_ = g_strdup (self->priv->_system_font);
		_g_free0 (_tmp1_);
		_tmp1_ = _tmp2_;
	} else {
		gchar* _tmp3_ = NULL;
		_tmp3_ = g_settings_get_string (self->priv->editor, "editor-font");
		_g_free0 (_tmp1_);
		_tmp1_ = _tmp3_;
	}
	_tmp4_ = g_strdup (_tmp1_);
	font = _tmp4_;
	app_settings_set_font (self, font);
	_g_free0 (font);
	_g_free0 (_tmp1_);
}


static void __lambda87__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda87_ (_sender, key, self);
}


static void _lambda88_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gboolean _tmp0_;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_boolean (self->priv->editor, "use-default-font");
	if (_tmp0_) {
		return;
	}
	_tmp1_ = g_settings_get_string (setting, key);
	_tmp2_ = _tmp1_;
	app_settings_set_font (self, _tmp2_);
	_g_free0 (_tmp2_);
}


static void __lambda88__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda88_ (_sender, key, self);
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


static void _lambda89_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gchar* _tmp0_ = NULL;
	gchar* scheme_id;
	GtkSourceStyleSchemeManager* _tmp1_ = NULL;
	GtkSourceStyleSchemeManager* _tmp2_;
	GtkSourceStyleSchemeManager* manager;
	GtkSourceStyleScheme* _tmp3_ = NULL;
	GtkSourceStyleScheme* _tmp4_;
	GtkSourceStyleScheme* scheme;
	Application* _tmp5_ = NULL;
	Application* _tmp6_;
	GList* _tmp7_ = NULL;
	GList* _tmp8_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_string (setting, key);
	scheme_id = _tmp0_;
	_tmp1_ = gtk_source_style_scheme_manager_get_default ();
	_tmp2_ = _g_object_ref0 (_tmp1_);
	manager = _tmp2_;
	_tmp3_ = gtk_source_style_scheme_manager_get_scheme (manager, scheme_id);
	_tmp4_ = _g_object_ref0 (_tmp3_);
	scheme = _tmp4_;
	_tmp5_ = application_get_default ();
	_tmp6_ = _tmp5_;
	_tmp7_ = application_get_documents (_tmp6_);
	_tmp8_ = _tmp7_;
	_g_object_unref0 (_tmp6_);
	{
		GList* doc_collection;
		GList* doc_it;
		doc_collection = _tmp8_;
		for (doc_it = doc_collection; doc_it != NULL; doc_it = doc_it->next) {
			Document* _tmp9_;
			Document* doc;
			_tmp9_ = _g_object_ref0 ((Document*) doc_it->data);
			doc = _tmp9_;
			{
				gtk_source_buffer_set_style_scheme ((GtkSourceBuffer*) doc, scheme);
				_g_object_unref0 (doc);
			}
		}
		__g_list_free__g_object_unref0_0 (doc_collection);
	}
	_g_object_unref0 (scheme);
	_g_object_unref0 (manager);
	_g_free0 (scheme_id);
}


static void __lambda89__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda89_ (_sender, key, self);
}


static void _lambda90_ (GSettings* setting, const gchar* key, AppSettings* self) {
	guint val = 0U;
	guint _tmp0_;
	Application* _tmp1_ = NULL;
	Application* _tmp2_;
	GList* _tmp3_ = NULL;
	GList* _tmp4_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	g_settings_get (setting, key, "u", &val);
	_tmp0_ = CLAMP (val, (guint) 1, (guint) 24);
	val = _tmp0_;
	_tmp1_ = application_get_default ();
	_tmp2_ = _tmp1_;
	_tmp3_ = application_get_views (_tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp2_);
	{
		GList* view_collection;
		GList* view_it;
		view_collection = _tmp4_;
		for (view_it = view_collection; view_it != NULL; view_it = view_it->next) {
			DocumentView* _tmp5_;
			DocumentView* view;
			_tmp5_ = _g_object_ref0 ((DocumentView*) view_it->data);
			view = _tmp5_;
			{
				gtk_source_view_set_tab_width ((GtkSourceView*) view, val);
				_g_object_unref0 (view);
			}
		}
		__g_list_free__g_object_unref0_0 (view_collection);
	}
}


static void __lambda90__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda90_ (_sender, key, self);
}


static void _lambda91_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gboolean _tmp0_;
	gboolean val;
	Application* _tmp1_ = NULL;
	Application* _tmp2_;
	GList* _tmp3_ = NULL;
	GList* _tmp4_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_boolean (setting, key);
	val = _tmp0_;
	_tmp1_ = application_get_default ();
	_tmp2_ = _tmp1_;
	_tmp3_ = application_get_views (_tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp2_);
	{
		GList* view_collection;
		GList* view_it;
		view_collection = _tmp4_;
		for (view_it = view_collection; view_it != NULL; view_it = view_it->next) {
			DocumentView* _tmp5_;
			DocumentView* view;
			_tmp5_ = _g_object_ref0 ((DocumentView*) view_it->data);
			view = _tmp5_;
			{
				gtk_source_view_set_insert_spaces_instead_of_tabs ((GtkSourceView*) view, val);
				_g_object_unref0 (view);
			}
		}
		__g_list_free__g_object_unref0_0 (view_collection);
	}
}


static void __lambda91__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda91_ (_sender, key, self);
}


static void _lambda92_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gboolean _tmp0_;
	gboolean val;
	Application* _tmp1_ = NULL;
	Application* _tmp2_;
	GList* _tmp3_ = NULL;
	GList* _tmp4_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_boolean (setting, key);
	val = _tmp0_;
	_tmp1_ = application_get_default ();
	_tmp2_ = _tmp1_;
	_tmp3_ = application_get_views (_tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp2_);
	{
		GList* view_collection;
		GList* view_it;
		view_collection = _tmp4_;
		for (view_it = view_collection; view_it != NULL; view_it = view_it->next) {
			DocumentView* _tmp5_;
			DocumentView* view;
			_tmp5_ = _g_object_ref0 ((DocumentView*) view_it->data);
			view = _tmp5_;
			{
				gtk_source_view_set_show_line_numbers ((GtkSourceView*) view, val);
				_g_object_unref0 (view);
			}
		}
		__g_list_free__g_object_unref0_0 (view_collection);
	}
}


static void __lambda92__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda92_ (_sender, key, self);
}


static void _lambda93_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gboolean _tmp0_;
	gboolean val;
	Application* _tmp1_ = NULL;
	Application* _tmp2_;
	GList* _tmp3_ = NULL;
	GList* _tmp4_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_boolean (setting, key);
	val = _tmp0_;
	_tmp1_ = application_get_default ();
	_tmp2_ = _tmp1_;
	_tmp3_ = application_get_views (_tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp2_);
	{
		GList* view_collection;
		GList* view_it;
		view_collection = _tmp4_;
		for (view_it = view_collection; view_it != NULL; view_it = view_it->next) {
			DocumentView* _tmp5_;
			DocumentView* view;
			_tmp5_ = _g_object_ref0 ((DocumentView*) view_it->data);
			view = _tmp5_;
			{
				gtk_source_view_set_highlight_current_line ((GtkSourceView*) view, val);
				_g_object_unref0 (view);
			}
		}
		__g_list_free__g_object_unref0_0 (view_collection);
	}
}


static void __lambda93__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda93_ (_sender, key, self);
}


static void _lambda94_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gboolean _tmp0_;
	gboolean val;
	Application* _tmp1_ = NULL;
	Application* _tmp2_;
	GList* _tmp3_ = NULL;
	GList* _tmp4_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_boolean (setting, key);
	val = _tmp0_;
	_tmp1_ = application_get_default ();
	_tmp2_ = _tmp1_;
	_tmp3_ = application_get_documents (_tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp2_);
	{
		GList* doc_collection;
		GList* doc_it;
		doc_collection = _tmp4_;
		for (doc_it = doc_collection; doc_it != NULL; doc_it = doc_it->next) {
			Document* _tmp5_;
			Document* doc;
			_tmp5_ = _g_object_ref0 ((Document*) doc_it->data);
			doc = _tmp5_;
			{
				gtk_source_buffer_set_highlight_matching_brackets ((GtkSourceBuffer*) doc, val);
				_g_object_unref0 (doc);
			}
		}
		__g_list_free__g_object_unref0_0 (doc_collection);
	}
}


static void __lambda94__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda94_ (_sender, key, self);
}


static void _lambda95_ (GSettings* setting, const gchar* key, AppSettings* self) {
	gboolean _tmp0_;
	gboolean val;
	Application* _tmp1_ = NULL;
	Application* _tmp2_;
	GList* _tmp3_ = NULL;
	GList* _tmp4_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = g_settings_get_boolean (setting, key);
	val = _tmp0_;
	_tmp1_ = application_get_default ();
	_tmp2_ = _tmp1_;
	_tmp3_ = application_get_documents (_tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp2_);
	{
		GList* doc_collection;
		GList* doc_it;
		doc_collection = _tmp4_;
		for (doc_it = doc_collection; doc_it != NULL; doc_it = doc_it->next) {
			Document* _tmp5_;
			Document* doc;
			_tmp5_ = _g_object_ref0 ((Document*) doc_it->data);
			doc = _tmp5_;
			{
				document_tab_set_auto_save (doc->tab, val);
				_g_object_unref0 (doc);
			}
		}
		__g_list_free__g_object_unref0_0 (doc_collection);
	}
}


static void __lambda95__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda95_ (_sender, key, self);
}


static void _lambda96_ (GSettings* setting, const gchar* key, AppSettings* self) {
	guint val = 0U;
	Application* _tmp0_ = NULL;
	Application* _tmp1_;
	GList* _tmp2_ = NULL;
	GList* _tmp3_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	g_settings_get (setting, key, "u", &val);
	_tmp0_ = application_get_default ();
	_tmp1_ = _tmp0_;
	_tmp2_ = application_get_documents (_tmp1_);
	_tmp3_ = _tmp2_;
	_g_object_unref0 (_tmp1_);
	{
		GList* doc_collection;
		GList* doc_it;
		doc_collection = _tmp3_;
		for (doc_it = doc_collection; doc_it != NULL; doc_it = doc_it->next) {
			Document* _tmp4_;
			Document* doc;
			_tmp4_ = _g_object_ref0 ((Document*) doc_it->data);
			doc = _tmp4_;
			{
				document_tab_set_auto_save_interval (doc->tab, val);
				_g_object_unref0 (doc);
			}
		}
		__g_list_free__g_object_unref0_0 (doc_collection);
	}
}


static void __lambda96__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda96_ (_sender, key, self);
}


static gboolean _lambda98_ (AppSettings* self) {
	gboolean result = FALSE;
	self->priv->timeout_id = (guint) 0;
	symbols_reload_most_used_symbols ();
	result = FALSE;
	return result;
}


static gboolean __lambda98__gsource_func (gpointer self) {
	gboolean result;
	result = _lambda98_ (self);
	return result;
}


static void _lambda97_ (GSettings* setting, const gchar* key, AppSettings* self) {
	guint _tmp0_;
	g_return_if_fail (setting != NULL);
	g_return_if_fail (key != NULL);
	if (self->priv->timeout_id != 0) {
		g_source_remove (self->priv->timeout_id);
	}
	_tmp0_ = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 1, __lambda98__gsource_func, g_object_ref (self), g_object_unref);
	self->priv->timeout_id = _tmp0_;
}


static void __lambda97__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	_lambda97_ (_sender, key, self);
}


static void app_settings_initialize (AppSettings* self) {
	GSettings* _tmp0_ = NULL;
	GSettings* _tmp1_;
	GSettings* prefs;
	GSettings* _tmp2_ = NULL;
	GSettings* _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_settings_get_child ((GSettings*) self, "preferences");
	_tmp1_ = _g_object_ref0 (_tmp0_);
	prefs = _tmp1_;
	_tmp2_ = g_settings_get_child (prefs, "editor");
	_tmp3_ = _g_object_ref0 (_tmp2_);
	_g_object_unref0 (self->priv->editor);
	self->priv->editor = _tmp3_;
	if (!DESKTOP_SCHEMAS) {
		app_settings_set_system_font (self, "Monospace 10");
	} else {
		GSettings* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_;
		_tmp4_ = g_settings_new ("org.gnome.desktop.interface");
		_g_object_unref0 (self->priv->desktop_interface);
		self->priv->desktop_interface = _tmp4_;
		_tmp5_ = g_settings_get_string (self->priv->desktop_interface, "monospace-font-name");
		_tmp6_ = _tmp5_;
		app_settings_set_system_font (self, _tmp6_);
		_g_free0 (_tmp6_);
		g_signal_connect_object (self->priv->desktop_interface, "changed::monospace-font-name", (GCallback) __lambda3__g_settings_changed, self, 0);
	}
	g_signal_connect_object (self->priv->editor, "changed::use-default-font", (GCallback) __lambda87__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::editor-font", (GCallback) __lambda88__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::scheme", (GCallback) __lambda89__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::tabs-size", (GCallback) __lambda90__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::insert-spaces", (GCallback) __lambda91__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::display-line-numbers", (GCallback) __lambda92__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::highlight-current-line", (GCallback) __lambda93__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::bracket-matching", (GCallback) __lambda94__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::auto-save", (GCallback) __lambda95__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::auto-save-interval", (GCallback) __lambda96__g_settings_changed, self, 0);
	g_signal_connect_object (self->priv->editor, "changed::nb-most-used-symbols", (GCallback) __lambda97__g_settings_changed, self, 0);
	_g_object_unref0 (prefs);
}


static void app_settings_set_font (AppSettings* self, const gchar* font) {
	Application* _tmp0_ = NULL;
	Application* _tmp1_;
	GList* _tmp2_ = NULL;
	GList* _tmp3_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (font != NULL);
	_tmp0_ = application_get_default ();
	_tmp1_ = _tmp0_;
	_tmp2_ = application_get_views (_tmp1_);
	_tmp3_ = _tmp2_;
	_g_object_unref0 (_tmp1_);
	{
		GList* view_collection;
		GList* view_it;
		view_collection = _tmp3_;
		for (view_it = view_collection; view_it != NULL; view_it = view_it->next) {
			DocumentView* _tmp4_;
			DocumentView* view;
			_tmp4_ = _g_object_ref0 ((DocumentView*) view_it->data);
			view = _tmp4_;
			{
				document_view_set_font_from_string (view, font);
				_g_object_unref0 (view);
			}
		}
		__g_list_free__g_object_unref0_0 (view_collection);
	}
}


const gchar* app_settings_get_system_font (AppSettings* self) {
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_system_font;
	return result;
}


static void app_settings_set_system_font (AppSettings* self, const gchar* value) {
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_system_font);
	self->priv->_system_font = _tmp0_;
	g_object_notify ((GObject *) self, "system-font");
}


static void app_settings_class_init (AppSettingsClass * klass) {
	app_settings_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (AppSettingsPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_app_settings_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_app_settings_set_property;
	G_OBJECT_CLASS (klass)->finalize = app_settings_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), APP_SETTINGS_SYSTEM_FONT, g_param_spec_string ("system-font", "system-font", "system-font", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void app_settings_instance_init (AppSettings * self) {
	self->priv = APP_SETTINGS_GET_PRIVATE (self);
	self->priv->timeout_id = (guint) 0;
}


static void app_settings_finalize (GObject* obj) {
	AppSettings * self;
	self = APP_SETTINGS (obj);
	_g_object_unref0 (self->priv->editor);
	_g_object_unref0 (self->priv->desktop_interface);
	_g_free0 (self->priv->_system_font);
	G_OBJECT_CLASS (app_settings_parent_class)->finalize (obj);
}


GType app_settings_get_type (void) {
	static volatile gsize app_settings_type_id__volatile = 0;
	if (g_once_init_enter (&app_settings_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (AppSettingsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) app_settings_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (AppSettings), 0, (GInstanceInitFunc) app_settings_instance_init, NULL };
		GType app_settings_type_id;
		app_settings_type_id = g_type_register_static (G_TYPE_SETTINGS, "AppSettings", &g_define_type_info, 0);
		g_once_init_leave (&app_settings_type_id__volatile, app_settings_type_id);
	}
	return app_settings_type_id__volatile;
}


static void _vala_app_settings_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	AppSettings * self;
	self = APP_SETTINGS (object);
	switch (property_id) {
		case APP_SETTINGS_SYSTEM_FONT:
		g_value_set_string (value, app_settings_get_system_font (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_app_settings_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	AppSettings * self;
	self = APP_SETTINGS (object);
	switch (property_id) {
		case APP_SETTINGS_SYSTEM_FONT:
		app_settings_set_system_font (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



