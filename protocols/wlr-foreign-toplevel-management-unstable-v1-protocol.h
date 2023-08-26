/* Generated by wayland-scanner 1.22.90 */

#ifndef WLR_FOREIGN_TOPLEVEL_MANAGEMENT_UNSTABLE_V1_CLIENT_PROTOCOL_H
#define WLR_FOREIGN_TOPLEVEL_MANAGEMENT_UNSTABLE_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_wlr_foreign_toplevel_management_unstable_v1 The wlr_foreign_toplevel_management_unstable_v1 protocol
 * @section page_ifaces_wlr_foreign_toplevel_management_unstable_v1 Interfaces
 * - @subpage page_iface_zwlr_foreign_toplevel_manager_v1 - list and control opened apps
 * - @subpage page_iface_zwlr_foreign_toplevel_handle_v1 - an opened toplevel
 * @section page_copyright_wlr_foreign_toplevel_management_unstable_v1 Copyright
 * <pre>
 *
 * Copyright © 2018 Ilia Bozhinov
 *
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 * </pre>
 */
struct wl_output;
struct wl_seat;
struct wl_surface;
struct zwlr_foreign_toplevel_handle_v1;
struct zwlr_foreign_toplevel_manager_v1;

#ifndef ZWLR_FOREIGN_TOPLEVEL_MANAGER_V1_INTERFACE
#define ZWLR_FOREIGN_TOPLEVEL_MANAGER_V1_INTERFACE
/**
 * @page page_iface_zwlr_foreign_toplevel_manager_v1 zwlr_foreign_toplevel_manager_v1
 * @section page_iface_zwlr_foreign_toplevel_manager_v1_desc Description
 *
 * The purpose of this protocol is to enable the creation of taskbars
 * and docks by providing them with a list of opened applications and
 * letting them request certain actions on them, like maximizing, etc.
 *
 * After a client binds the zwlr_foreign_toplevel_manager_v1, each opened
 * toplevel window will be sent via the toplevel event
 * @section page_iface_zwlr_foreign_toplevel_manager_v1_api API
 * See @ref iface_zwlr_foreign_toplevel_manager_v1.
 */
/**
 * @defgroup iface_zwlr_foreign_toplevel_manager_v1 The zwlr_foreign_toplevel_manager_v1 interface
 *
 * The purpose of this protocol is to enable the creation of taskbars
 * and docks by providing them with a list of opened applications and
 * letting them request certain actions on them, like maximizing, etc.
 *
 * After a client binds the zwlr_foreign_toplevel_manager_v1, each opened
 * toplevel window will be sent via the toplevel event
 */
extern const struct wl_interface zwlr_foreign_toplevel_manager_v1_interface;
#endif
#ifndef ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_INTERFACE
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_INTERFACE
/**
 * @page page_iface_zwlr_foreign_toplevel_handle_v1 zwlr_foreign_toplevel_handle_v1
 * @section page_iface_zwlr_foreign_toplevel_handle_v1_desc Description
 *
 * A zwlr_foreign_toplevel_handle_v1 object represents an opened toplevel
 * window. Each app may have multiple opened toplevels.
 *
 * Each toplevel has a list of outputs it is visible on, conveyed to the
 * client with the output_enter and output_leave events.
 * @section page_iface_zwlr_foreign_toplevel_handle_v1_api API
 * See @ref iface_zwlr_foreign_toplevel_handle_v1.
 */
/**
 * @defgroup iface_zwlr_foreign_toplevel_handle_v1 The zwlr_foreign_toplevel_handle_v1 interface
 *
 * A zwlr_foreign_toplevel_handle_v1 object represents an opened toplevel
 * window. Each app may have multiple opened toplevels.
 *
 * Each toplevel has a list of outputs it is visible on, conveyed to the
 * client with the output_enter and output_leave events.
 */
extern const struct wl_interface zwlr_foreign_toplevel_handle_v1_interface;
#endif

/**
 * @ingroup iface_zwlr_foreign_toplevel_manager_v1
 * @struct zwlr_foreign_toplevel_manager_v1_listener
 */
struct zwlr_foreign_toplevel_manager_v1_listener {
	/**
	 * a toplevel has been created
	 *
	 * This event is emitted whenever a new toplevel window is
	 * created. It is emitted for all toplevels, regardless of the app
	 * that has created them.
	 *
	 * All initial details of the toplevel(title, app_id, states, etc.)
	 * will be sent immediately after this event via the corresponding
	 * events in zwlr_foreign_toplevel_handle_v1.
	 */
	void (*toplevel)(void *data,
			 struct zwlr_foreign_toplevel_manager_v1 *zwlr_foreign_toplevel_manager_v1,
			 struct zwlr_foreign_toplevel_handle_v1 *toplevel);
	/**
	 * the compositor has finished with the toplevel manager
	 *
	 * This event indicates that the compositor is done sending
	 * events to the zwlr_foreign_toplevel_manager_v1. The server will
	 * destroy the object immediately after sending this request, so it
	 * will become invalid and the client should free any resources
	 * associated with it.
	 */
	void (*finished)(void *data,
			 struct zwlr_foreign_toplevel_manager_v1 *zwlr_foreign_toplevel_manager_v1);
};

/**
 * @ingroup iface_zwlr_foreign_toplevel_manager_v1
 */
static inline int
zwlr_foreign_toplevel_manager_v1_add_listener(struct zwlr_foreign_toplevel_manager_v1 *zwlr_foreign_toplevel_manager_v1,
					      const struct zwlr_foreign_toplevel_manager_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwlr_foreign_toplevel_manager_v1,
				     (void (**)(void)) listener, data);
}

#define ZWLR_FOREIGN_TOPLEVEL_MANAGER_V1_STOP 0

/**
 * @ingroup iface_zwlr_foreign_toplevel_manager_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_MANAGER_V1_TOPLEVEL_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_manager_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_MANAGER_V1_FINISHED_SINCE_VERSION 1

/**
 * @ingroup iface_zwlr_foreign_toplevel_manager_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_MANAGER_V1_STOP_SINCE_VERSION 1

/** @ingroup iface_zwlr_foreign_toplevel_manager_v1 */
static inline void
zwlr_foreign_toplevel_manager_v1_set_user_data(struct zwlr_foreign_toplevel_manager_v1 *zwlr_foreign_toplevel_manager_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwlr_foreign_toplevel_manager_v1, user_data);
}

/** @ingroup iface_zwlr_foreign_toplevel_manager_v1 */
static inline void *
zwlr_foreign_toplevel_manager_v1_get_user_data(struct zwlr_foreign_toplevel_manager_v1 *zwlr_foreign_toplevel_manager_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwlr_foreign_toplevel_manager_v1);
}

static inline uint32_t
zwlr_foreign_toplevel_manager_v1_get_version(struct zwlr_foreign_toplevel_manager_v1 *zwlr_foreign_toplevel_manager_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_manager_v1);
}

/** @ingroup iface_zwlr_foreign_toplevel_manager_v1 */
static inline void
zwlr_foreign_toplevel_manager_v1_destroy(struct zwlr_foreign_toplevel_manager_v1 *zwlr_foreign_toplevel_manager_v1)
{
	wl_proxy_destroy((struct wl_proxy *) zwlr_foreign_toplevel_manager_v1);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_manager_v1
 *
 * Indicates the client no longer wishes to receive events for new toplevels.
 * However the compositor may emit further toplevel_created events, until
 * the finished event is emitted.
 *
 * The client must not send any more requests after this one.
 */
static inline void
zwlr_foreign_toplevel_manager_v1_stop(struct zwlr_foreign_toplevel_manager_v1 *zwlr_foreign_toplevel_manager_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_manager_v1,
			 ZWLR_FOREIGN_TOPLEVEL_MANAGER_V1_STOP, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_manager_v1), 0);
}

#ifndef ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_ENUM
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_ENUM
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 * types of states on the toplevel
 *
 * The different states that a toplevel can have. These have the same meaning
 * as the states with the same names defined in xdg-toplevel
 */
enum zwlr_foreign_toplevel_handle_v1_state {
	/**
	 * the toplevel is maximized
	 */
	ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_MAXIMIZED = 0,
	/**
	 * the toplevel is minimized
	 */
	ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_MINIMIZED = 1,
	/**
	 * the toplevel is active
	 */
	ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_ACTIVATED = 2,
	/**
	 * the toplevel is fullscreen
	 * @since 2
	 */
	ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_FULLSCREEN = 3,
};
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_FULLSCREEN_SINCE_VERSION 2
#endif /* ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_ENUM */

#ifndef ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_ERROR_ENUM
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_ERROR_ENUM
enum zwlr_foreign_toplevel_handle_v1_error {
	/**
	 * the provided rectangle is invalid
	 */
	ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_ERROR_INVALID_RECTANGLE = 0,
};
#endif /* ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_ERROR_ENUM */

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 * @struct zwlr_foreign_toplevel_handle_v1_listener
 */
struct zwlr_foreign_toplevel_handle_v1_listener {
	/**
	 * title change
	 *
	 * This event is emitted whenever the title of the toplevel
	 * changes.
	 */
	void (*title)(void *data,
		      struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1,
		      const char *title);
	/**
	 * app-id change
	 *
	 * This event is emitted whenever the app-id of the toplevel
	 * changes.
	 */
	void (*app_id)(void *data,
		       struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1,
		       const char *app_id);
	/**
	 * toplevel entered an output
	 *
	 * This event is emitted whenever the toplevel becomes visible on
	 * the given output. A toplevel may be visible on multiple outputs.
	 */
	void (*output_enter)(void *data,
			     struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1,
			     struct wl_output *output);
	/**
	 * toplevel left an output
	 *
	 * This event is emitted whenever the toplevel stops being
	 * visible on the given output. It is guaranteed that an
	 * entered-output event with the same output has been emitted
	 * before this event.
	 */
	void (*output_leave)(void *data,
			     struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1,
			     struct wl_output *output);
	/**
	 * the toplevel state changed
	 *
	 * This event is emitted immediately after the
	 * zlw_foreign_toplevel_handle_v1 is created and each time the
	 * toplevel state changes, either because of a compositor action or
	 * because of a request in this protocol.
	 */
	void (*state)(void *data,
		      struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1,
		      struct wl_array *state);
	/**
	 * all information about the toplevel has been sent
	 *
	 * This event is sent after all changes in the toplevel state
	 * have been sent.
	 *
	 * This allows changes to the zwlr_foreign_toplevel_handle_v1
	 * properties to be seen as atomic, even if they happen via
	 * multiple events.
	 */
	void (*done)(void *data,
		     struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1);
	/**
	 * this toplevel has been destroyed
	 *
	 * This event means the toplevel has been destroyed. It is
	 * guaranteed there won't be any more events for this
	 * zwlr_foreign_toplevel_handle_v1. The toplevel itself becomes
	 * inert so any requests will be ignored except the destroy
	 * request.
	 */
	void (*closed)(void *data,
		       struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1);
	/**
	 * parent change
	 *
	 * This event is emitted whenever the parent of the toplevel
	 * changes.
	 *
	 * No event is emitted when the parent handle is destroyed by the
	 * client.
	 * @since 3
	 */
	void (*parent)(void *data,
		       struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1,
		       struct zwlr_foreign_toplevel_handle_v1 *parent);
};

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
static inline int
zwlr_foreign_toplevel_handle_v1_add_listener(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1,
					     const struct zwlr_foreign_toplevel_handle_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
				     (void (**)(void)) listener, data);
}

#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_MAXIMIZED 0
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_MAXIMIZED 1
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_MINIMIZED 2
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_MINIMIZED 3
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_ACTIVATE 4
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_CLOSE 5
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_RECTANGLE 6
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_DESTROY 7
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_FULLSCREEN 8
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_FULLSCREEN 9

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_TITLE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_APP_ID_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_OUTPUT_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_OUTPUT_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_STATE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_DONE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_CLOSED_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_PARENT_SINCE_VERSION 3

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_MAXIMIZED_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_MAXIMIZED_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_MINIMIZED_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_MINIMIZED_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_ACTIVATE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_CLOSE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_RECTANGLE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_FULLSCREEN_SINCE_VERSION 2
/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 */
#define ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_FULLSCREEN_SINCE_VERSION 2

/** @ingroup iface_zwlr_foreign_toplevel_handle_v1 */
static inline void
zwlr_foreign_toplevel_handle_v1_set_user_data(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1, user_data);
}

/** @ingroup iface_zwlr_foreign_toplevel_handle_v1 */
static inline void *
zwlr_foreign_toplevel_handle_v1_get_user_data(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1);
}

static inline uint32_t
zwlr_foreign_toplevel_handle_v1_get_version(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Requests that the toplevel be maximized. If the maximized state actually
 * changes, this will be indicated by the state event.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_set_maximized(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_MAXIMIZED, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Requests that the toplevel be unmaximized. If the maximized state actually
 * changes, this will be indicated by the state event.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_unset_maximized(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_MAXIMIZED, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Requests that the toplevel be minimized. If the minimized state actually
 * changes, this will be indicated by the state event.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_set_minimized(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_MINIMIZED, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Requests that the toplevel be unminimized. If the minimized state actually
 * changes, this will be indicated by the state event.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_unset_minimized(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_MINIMIZED, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Request that this toplevel be activated on the given seat.
 * There is no guarantee the toplevel will be actually activated.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_activate(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1, struct wl_seat *seat)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_ACTIVATE, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0, seat);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Send a request to the toplevel to close itself. The compositor would
 * typically use a shell-specific method to carry out this request, for
 * example by sending the xdg_toplevel.close event. However, this gives
 * no guarantees the toplevel will actually be destroyed. If and when
 * this happens, the zwlr_foreign_toplevel_handle_v1.closed event will
 * be emitted.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_close(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_CLOSE, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * The rectangle of the surface specified in this request corresponds to
 * the place where the app using this protocol represents the given toplevel.
 * It can be used by the compositor as a hint for some operations, e.g
 * minimizing. The client is however not required to set this, in which
 * case the compositor is free to decide some default value.
 *
 * If the client specifies more than one rectangle, only the last one is
 * considered.
 *
 * The dimensions are given in surface-local coordinates.
 * Setting width=height=0 removes the already-set rectangle.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_set_rectangle(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1, struct wl_surface *surface, int32_t x, int32_t y, int32_t width, int32_t height)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_RECTANGLE, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0, surface, x, y, width, height);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Destroys the zwlr_foreign_toplevel_handle_v1 object.
 *
 * This request should be called either when the client does not want to
 * use the toplevel anymore or after the closed event to finalize the
 * destruction of the object.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_destroy(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Requests that the toplevel be fullscreened on the given output. If the
 * fullscreen state and/or the outputs the toplevel is visible on actually
 * change, this will be indicated by the state and output_enter/leave
 * events.
 *
 * The output parameter is only a hint to the compositor. Also, if output
 * is NULL, the compositor should decide which output the toplevel will be
 * fullscreened on, if at all.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_set_fullscreen(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1, struct wl_output *output)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_SET_FULLSCREEN, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0, output);
}

/**
 * @ingroup iface_zwlr_foreign_toplevel_handle_v1
 *
 * Requests that the toplevel be unfullscreened. If the fullscreen state
 * actually changes, this will be indicated by the state event.
 */
static inline void
zwlr_foreign_toplevel_handle_v1_unset_fullscreen(struct zwlr_foreign_toplevel_handle_v1 *zwlr_foreign_toplevel_handle_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1,
			 ZWLR_FOREIGN_TOPLEVEL_HANDLE_V1_UNSET_FULLSCREEN, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_foreign_toplevel_handle_v1), 0);
}

#ifdef  __cplusplus
}
#endif

#endif
