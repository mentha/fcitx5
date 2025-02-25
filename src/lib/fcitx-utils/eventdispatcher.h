/*
 * SPDX-FileCopyrightText: 2015-2019 CSSlayer <wengxt@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 */

#ifndef _FCITX_UTILS_EVENTDISPATCHER_H_
#define _FCITX_UTILS_EVENTDISPATCHER_H_

#include <functional>
#include <memory>
#include <fcitx-utils/macros.h>
#include "fcitxutils_export.h"

namespace fcitx {

class EventLoop;
class EventDispatcherPrivate;
/**
 * A thread safe class to post event to a certain EventLoop.
 *
 */
class FCITXUTILS_EXPORT EventDispatcher {
public:
    /**
     * Construct a new event dispatcher. May throw exception if it fails to
     * create underlying file descriptor.
     */
    EventDispatcher();
    virtual ~EventDispatcher();

    /**
     * Attach EventDispatcher to an EventLoop. Must be called in the same thread
     * of EventLoop.
     *
     * @param event event loop to attach to.
     */
    void attach(EventLoop *event);

    /**
     * Detach event dispatcher from event loop, must be called from the same
     * thread from event loop.
     */
    void detach();
    /**
     * A thread-safe function to schedule a functor to be call from event loop.
     *
     * @param functor functor to be called.
     */
    void schedule(std::function<void()> functor);

    /**
     * Return the currently attached event loop
     *
     * @since 5.0.11
     */
    EventLoop *eventLoop() const;

private:
    const std::unique_ptr<EventDispatcherPrivate> d_ptr;
    FCITX_DECLARE_PRIVATE(EventDispatcher);
};

} // namespace fcitx
#endif // _FCITX_UTILS_EVENTDISPATCHER_H_
