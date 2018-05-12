ee_setup_project("EssexEngineAppEditor" "src/Apps/Editor/")

target_link_libraries(EssexEngineAppEditor EssexEngineCore)
target_link_libraries(EssexEngineAppEditor EssexEngineLibIsoMap)
target_link_libraries(EssexEngineAppEditor EssexEngineJsonDaemon)
target_link_libraries(EssexEngineAppEditor EssexEngineFileSystemDaemon)
target_link_libraries(EssexEngineAppEditor EssexEngineInputDaemon)
target_link_libraries(EssexEngineAppEditor EssexEngineWindowDaemon)
target_link_libraries(EssexEngineAppEditor EssexEngineAppGame)

add_custom_target(runEditor
    COMMAND EssexEngineBootloader --editor
    DEPENDS EssexEngineBootloader
    WORKING_DIRECTORY ../filesystem
)
