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

#include <EssexEngineCore/EssexEnvironment.h>

#include <EssexEngineAppEditor/IEditorWindow.h>

namespace EssexEngine{
namespace Apps{
namespace Editor{
namespace Windows{
    class MapSelectorWindow:public IEditorWindow
    {
    public:
        MapSelectorWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::string _currentMapFile, std::function<void(std::string)> _changeMap, std::function<void()> _close);
        ~MapSelectorWindow();
        
        //override
        void Logic();
        void Render();
    protected:
        std::function<void(std::string)> changeMap;
    private:
        int selectedMap;
        std::vector<std::string> maps;
    };
}}}};
