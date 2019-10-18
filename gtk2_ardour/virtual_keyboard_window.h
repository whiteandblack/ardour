/*
 * Copyright (C) 2019 Robin Gareus <robin@gareus.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _virtual_keyboard_window_h_
#define _virtual_keyboard_window_h_

#include "ardour_window.h"
#include "gtk_pianokeyboard.h"

namespace ARDOUR {
	class Session;
}

class VirtualKeyboardWindow : public ArdourWindow
{
public:
	VirtualKeyboardWindow ();
	~VirtualKeyboardWindow ();

protected:
	void on_unmap ();
	bool on_key_press_event (GdkEventKey*);

private:
	static void _note_on_event_handler (GtkWidget*, int note, gpointer arg)
	{
		static_cast<VirtualKeyboardWindow*>(arg)->note_on_event_handler(note);
	}

	static void _note_off_event_handler (GtkWidget*, int note, gpointer arg) 
	{
		static_cast<VirtualKeyboardWindow*>(arg)->note_off_event_handler(note);
	}

	void note_on_event_handler  (int);
	void note_off_event_handler (int);

	PianoKeyboard*  _piano;
	Gtk::Widget*    _pianomm;
	Gtk::SpinButton _piano_velocity;
	Gtk::SpinButton _piano_channel;
};

#endif