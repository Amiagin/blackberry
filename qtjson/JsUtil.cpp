/*
 * Version: 0.1
 * Git https://github.com/Amiagin/blackberry/qtjson
 *
 * JsUtil.cpp
 *
 *  Created on: Mar 22, 2013
 *      Author: Christopher.D
 */

#include "JsUtil.h"

namespace QtJson {
    JsUtil::JsUtil() {
    }

    JsUtil::~JsUtil() {
    }

    void JsUtil::init(QVariant qtObject) {
        this->qtObject = qtObject;
    }

    bool JsUtil::isBool(QString key) {
        return qvariant_cast<QVariantMap>(qtObject)[key].type() == QVariant::Bool;
    }

    bool JsUtil::isString(QString key) {
        return qvariant_cast<QVariantMap>(qtObject)[key].type() == QVariant::String;
    }

    bool JsUtil::isInt(QString key) {
        return qvariant_cast<QVariantMap>(qtObject)[key].type() == QVariant::Int;
    }

    bool JsUtil::isDouble(QString key) {
        return qvariant_cast<QVariantMap>(qtObject)[key].type() == QVariant::Double;
    }

    bool JsUtil::isObject(QString key) {
        return qvariant_cast<QVariantMap>(qtObject)[key].type() == QVariant::Map;
    }

    bool JsUtil::isArray(QString key) {
        return qvariant_cast<QVariantMap>(qtObject)[key].type() == QVariant::List;
    }

    bool JsUtil::isLong(QString key) {
        return qvariant_cast<QVariantMap>(qtObject)[key].type() == QVariant::LongLong;
    }

    void JsUtil::toString(QVariant object,QString &output) {
     	if (object.type() == QVariant::Map) {
            QMapIterator<QString,QVariant> iter(object.value<QVariantMap>());
            QString sep = "";
            if (iter.hasNext()) {
                output += "{";
                do {
                	iter.next();
                	output += sep;
                 	output += iter.key();
                 	output += ":";
                    toString(iter.value(),output);
                    sep = ",";
                } while (iter.hasNext());
                output += "}";
            }
    	} else if (object.type() == QVariant::List) {
            QListIterator<QVariant> iter (object.value<QVariantList>());
            QString sep = "";
            if (iter.hasNext()) {
            	output += "[";
                do {
                	output += sep;
                    toString(iter.next(),output);
                    sep = ",";
                } while (iter.hasNext());
                output += "]";
            }
     	} else if (object.type() == QVariant::String) {
     		output += "\"" + object.toString() + "\"";
     	} else if (object.type() == QVariant::Bool || object.type() == QVariant::Int || object.type() == QVariant::Double || object.type() == QVariant::LongLong) {
            output += object.toString();
     	}
    }
}