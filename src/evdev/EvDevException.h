//
// Created by thonkdifferent on 01.06.24.
//

#ifndef EVDEVEXCEPTION_H
#define EVDEVEXCEPTION_H
#include <exception>
#include <QMessageBox>
#include <iostream>
#define GUARD(statement,error_code) if(statement==error_code)\
{\
std::stringstream message;\
message<<"Guard error: "<<"function"<<#statement<<" returned "<<#error_code;\
QMessageBox::critical(nullptr, QString::fromUtf8("EvDev error"), QString::fromStdString(message.str())); \
std::cerr<<message.str(); \
this->fail = 1; \
return;\
}
#define GUARD_NULL(statement) GUARD(statement,nullptr)
#define GUARD_NEG1(statement) GUARD(statement, -1)

#define GUARD_NOT(statement,success_code) {auto result = statement; if(result!=success_code)\
{\
std::stringstream message;\
message<<"Guard error: "<<"function"<<#statement<<" returned "<<result;\
std::string message_str(message.str());\
this->fail = 1; \
std::cerr<<message.str(); \
QMessageBox::critical(nullptr, QString::fromUtf8("EvDev error"), QString::fromStdString(message.str())); \
return;\
}}
#define GUARD_NERR(statement) GUARD_NOT(statement,0)
#define UNWRAP(variable, statement, error_code) variable = statement; if (variable == error_code){\
std::stringstream message;\
message<<"Unwrap error: "<<"function"<<#statement<<" returned "<<#error_code;\
std::string message_str(message.str());\
this->fail = 1; \
std::cerr<<message.str(); \
QMessageBox::critical(nullptr, QString::fromUtf8("EvDev error"), QString::fromStdString(message.str())); \
return;\
}

#define UNWRAP_NULL(variable,statement) UNWRAP(variable,statement,nullptr)


#endif //EVDEVEXCEPTION_H
