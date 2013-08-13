/*
 * Version: 0.1
 * Git https://github.com/Amiagin/blackberry/qtjson
 *
 * JsObject.cpp
 *
 *  Created on: Mar 22, 2013
 *      Author: Christopher.D
 */

#include "JsObject.h"

namespace QtJson {
    JsObject::JsObject() {
        this->serialize = true;
        qtObject = QVariantMap();
    }

    JsObject::JsObject(QString data) {
        JsonDataAccess jda;
        error = false;

        QVariant qtObject = jda.loadFromBuffer(data);
        if (jda.hasError()) {
        	error = true;
        } else {
            this->qtObject = qtObject.value<QVariantMap>();
            init(this->qtObject);

            this->serialize = false;
        }
    }

    JsObject::JsObject(QVariant qtObject) {
        this->qtObject = qtObject.value<QVariantMap>();
	    init(this->qtObject);

        this->serialize = false;
    }

    JsObject::~JsObject() {
       	this->serialize = false;
    }

    bool JsObject::has(QString key) {
        return qtObject.contains(key);
    }

    JsObject *JsObject::getObject(QString key) {
        return new JsObject(qtObject[key]);
    }

    JsArray *JsObject::getArray(QString key) {
	    return new JsArray(qtObject[key]);
    }

    int JsObject::getNumber(QString key) {
        return qtObject[key].value<int>();
    }

    QString JsObject::getString(QString key) {
        return qtObject[key].value<QString>();
    }

    bool JsObject::hasError() {
      	return error;
    }

    QVariant JsObject::getJsObject() {
        return qtObject;
    }

    QString JsObject::toString() {
        QString output;
     	JsUtil::toString(QVariant(qtObject),output);
     	return output;
    }

    void JsObject::setProperty(QString key, QString value) {
        qtObject[key] = QVariant(value);
    }

    void JsObject::setProperty(QString key,int value) {
      	qtObject[key] = QVariant(value);
    }

    void JsObject::setProperty(QString key,double value) {
     	qtObject[key] = QVariant(value);
    }

    void JsObject::setProperty(QString key,qlonglong value) {
      	qtObject[key] = QVariant(value);
    }

    void JsObject::setProperty(QString key, JsObject *object) {
        qtObject[key] = object->getJsObject();
    }

    void JsObject::setProperty(QString key,JsArray *array) {
     	qtObject[key] = QVariant(array->getArray());
    }
}