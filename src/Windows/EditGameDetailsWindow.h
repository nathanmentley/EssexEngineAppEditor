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

#include <EssexEngineAppEditor/IEditorWindow.h>

namespace EssexEngine{
namespace Apps{
namespace Editor{
namespace Windows{
    class EditGameDetailsWindow:public IEditorWindow
    {
    public:
        EditGameDetailsWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close);
        ~EditGameDetailsWindow();
        
        //override
        void Logic();
        void Render();
    private:
        //char* gameName;
        //int selectedMap;
        //std::vector<std::string> maps;
    };
}}}};
