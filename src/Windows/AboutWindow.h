/* 
 * Essex Engine
 * 
 * Copyright (C) 2017 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */
#pragma once

#include <functional>

#include <EssexEngineCore/EssexEnvironment.h>

#include <EssexEngineAppEditor/IEditorWindow.h>

namespace EssexEngine{
namespace Apps{
namespace Editor{
namespace Windows{
    class AboutWindow:public IEditorWindow
    {
    public:
        AboutWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close);
        ~AboutWindow();
        
        //override
        void Logic();
        void Render();
        
        void ButtonClick();
        void WindowClose();
    private:
        EssexEngine::WeakPointer<EssexEngine::Daemons::Window::IWindow> tempWindow;
    };
}}}};
