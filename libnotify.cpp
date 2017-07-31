#include "libnotify.h"

Libnotify::Libnotify(const std::string& appName){
	notify_init(appName.c_str());
}

Libnotify::~Libnotify(){
	notify_uninit();
}

bool Libnotify::isInitted(){
	return (notify_is_initted() == TRUE);
}

std::string Libnotify::getAppName(){
	return std::string(notify_get_app_name());
}

void Libnotify::setAppName(const std::string& name){
	notify_set_app_name(name.c_str());
}

GList* getServerCaps(){
	return notify_get_server_caps();
}

bool getServerInfo(std::string& retName, std::string& retVendor, std::string& retVersion, std::string& retSpecialVersion){
	char rName[1024];
	char rVendor[1024];
	char rVersion[1024];
	char rSVersion[1024];
	bool ret;
	ret = (notify_get_server_info((char**)&rName, (char**)&rVendor, (char**)&rVersion, (char**)&rSVersion) == TRUE);
	retName = std::string(rName);
	retVendor = std::string(rVendor);
	retVersion = std::string(rVersion);
	retSpecialVersion = std::string(rSVersion);
	return ret;
}
