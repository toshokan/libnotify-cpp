#include "libnotifynotification.h"

LibnotifyNotification::LibnotifyNotification(const std::string& summary, const std::string& body, const std::string& icon){
	this->notification = notify_notification_new(summary.c_str(), body.c_str(), icon.c_str());
}

LibnotifyNotification::~LibnotifyNotification(){
	free(this->notification);
}

bool LibnotifyNotification::update(const std::string& summary, const std::string& body, const std::string& icon){
	return (notify_notification_update(this->notification, summary.c_str(), body.c_str(), icon.c_str())==TRUE);
}

bool LibnotifyNotification::show(GError** error){
	return (notify_notification_show(this->notification, error) == TRUE);
}

void LibnotifyNotification::setAppName(const std::string& appName){
	notify_notification_set_app_name(this->notification, appName.c_str());
}

void LibnotifyNotification::setTimeout(const int& timeout){
	notify_notification_set_timeout(this->notification, timeout);
}

void LibnotifyNotification::setCategory(const std::string& category){
	notify_notification_set_category(this->notification, category.c_str());
}

void LibnotifyNotification::setUrgency(const NotifyUrgency& urgency){
	notify_notification_set_urgency(this->notification, urgency);
}

void LibnotifyNotification::setImageFromPixbuf(GdkPixbuf* pixbuf){
	notify_notification_set_image_from_pixbuf(this->notification, pixbuf);
}

void LibnotifyNotification::setHint(const std::string& key, GVariant* value){
	notify_notification_set_hint(this->notification, key.c_str(), value);
}

void LibnotifyNotification::clearHints(){
	notify_notification_clear_hints(this->notification);
}

void LibnotifyNotification::addAction(const std::string& action, const std::string& label, NotifyActionCallback callback, gpointer user_data, GFreeFunc free_func){
	notify_notification_add_action(this->notification, action.c_str(), label.c_str(), callback, user_data, free_func);
}

void LibnotifyNotification::clearActions(){
	notify_notification_clear_actions(this->notification);
}

bool LibnotifyNotification::close(GError** error){
	return (notify_notification_close(this->notification, error) == TRUE);
}

int LibnotifyNotification::getClosedReason(){
	return notify_notification_get_closed_reason(this->notification);
}
