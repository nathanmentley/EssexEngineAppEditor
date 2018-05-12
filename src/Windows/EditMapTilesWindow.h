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
    class EditMapTilesWindow:public IEditorWindow
    {
    public:
        EditMapTilesWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close);
        ~EditMapTilesWindow();
        
        //override
        void Logic();
        void Render();
    private:
        struct maptiledef {
            int x;
            int y;
            char* filename;
            bool blocking;
        };
        std::vector<maptiledef> tiles;
    };
}}}};
