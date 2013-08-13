/*
 * Version: 0.1
 * Git https://github.com/Amiagin/blackberry/qtjson
 *
 * JsArray.cpp
 *
 *  Created on: Mar 22, 2013
 *      Author: Christopher.D
 */

#include "JsArray.h"

namespace QtJson {
    JsArray::JsArray() {
        this->qtObject = QVariantList();
        init(this->qtObject);
    }
   
    JsArray::JsArray(QVariant qtObject) {
    	init(qtObject);
        this->qtObject = qtObject.value<QVariantList>();
    }

    JsArray::~JsArray() {
    }

    JsObject *JsArray::getObject(int index) {
	    return new JsObject(qtObject.at(index));
    }

    QVariant JsArray::getArray() {
        return QVariant(qtObject);
    }

    void JsArray::put(QVariant value) {
    	this->qtObject.append(value);
    }

    void JsArray::put(JsObject *object) {
        this->qtObject.append(object->getJsObject());
    }

    int JsArray::size() {
        return this->qtObject.size();
    }
}
