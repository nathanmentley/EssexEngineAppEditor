/* 
 * Essex Engine
 * 
 * Copyright (C) 2018 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */
#pragma once

#include <functional>

#include <EssexEngineCore/EssexEnvironment.h>

#include <EssexEngineWindowDaemon/Window.h>
#include <EssexEngineWindowDaemon/WindowDaemon.h>
#include <EssexEngineJsonDaemon/IJsonDocument.h>

#include <EssexEngineAppEditor/Daemons.h>

namespace EssexEngine{
namespace Apps{
namespace Editor{
namespace Windows{
    class AboutWindow:public Daemons::Window::Window
    {
    public:
        AboutWindow(
            WeakPointer<Context> _context,
            WeakPointer<Daemons::Json::IJsonDocument> _gameDocument,
            std::function<void()> _close
        );
        
        void ButtonClick();
        void WindowClose();
    private:
        UniquePointer<Daemons::Window::LabelDef> label;
        UniquePointer<Daemons::Window::ButtonDef> button;
        
        WeakPointer<Daemons::Json::IJsonDocument> gameDocument;
    };
}}}};
