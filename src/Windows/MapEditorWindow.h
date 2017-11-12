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

#include <EssexEngineLibIsoMap/Map.h>

#include <EssexEngineAppEditor/IEditorWindow.h>

namespace EssexEngine{
namespace Apps{
namespace Editor{
namespace Windows{
    class MapEditorWindow:public IEditorWindow
    {
    public:
        MapEditorWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, WeakPointer<Daemons::Json::IJsonDocument> _mapDocument, std::function<void()> _close);
        ~MapEditorWindow();
        
        //override
        void Logic();
        void Render();
    protected:
        void UpdateTile(int id);
        void UpdateDoodads(int id);
        void UpdateCharacter(int id);
        void UpdatePlayer(int id);
        
        void RefreshMap();
    private:
        WeakPointer<Daemons::Json::IJsonDocument> mapDocument;
        Libs::IsoMap::Map* map;
        UniquePointer<Daemons::Gfx::Entity> selectedTileOverlay;
        int activeTab;
    };
}}}};
