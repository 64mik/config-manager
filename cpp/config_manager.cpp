#include "config_manager.h"
#include "mlog.h"
ConfigManager::ConfigManager(const std::string& filename){
    MLOG_SET_WRITERS("file");
    MLOG_INFO_S << "hellp" << "what is this?" << 5;
}
ConfigManager::~ConfigManager(){

}