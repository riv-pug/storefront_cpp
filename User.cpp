#include "User.h"

User::User() {}

User::User(string user, string pass, string type){
	username = user;
	password = pass;
	usertype = type;


}



string User::getUserName() { return username; }
string User::getUserType() { return usertype; }
