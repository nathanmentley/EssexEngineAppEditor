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

#include <map>

#include <EssexEngineAppEditor/IEditorWindow.h>

const int MAX_SCRIPT_NAME_SIZE = 1024;
const int MAX_SCRIPT_CODE_SIZE = 65536;

namespace EssexEngine{
namespace Apps{
namespace Editor{
namespace Windows{
    class MapScriptEditorWindow:public IEditorWindow
    {
    public:
        MapScriptEditorWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, Daemons::Json::IJsonDocument* _mapDocument, std::string _currentMapFile, std::function<void()> _close);
        ~MapScriptEditorWindow();
        
        //override
        void Logic();
        void Render();
    private:
        struct scriptdef {
            char* name;
            char* code;
        };
        Daemons::Json::IJsonDocument* mapDocument;
        std::string currentMapFile;
        std::map<std::string, std::vector<scriptdef>> scripts;
    };
}}}};
