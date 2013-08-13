/*
 * Version: 0.1
 * Git https://github.com/Amiagin/blackberry/qtjson
 *
 * JsUtil.h
 *
 *  Created on: Mar 22, 2013
 *      Author: Christopher.D
 */

#ifndef QT_JSUTIL_H_
#define QT_JSUTIL_H_

#include <bb/data/JsonDataAccess>

namespace QtJson {
    class JsUtil {
    private:
        QVariant qtObject;

    public:
	    JsUtil();
	    virtual ~JsUtil();

	    void init(QVariant qtObject);

        bool isBool(QString key);
        bool isString(QString key);
        bool isInt(QString key);
        bool isDouble(QString key);
        bool isObject(QString key);
        bool isArray(QString key);
        bool isLong(QString key);

        static void toString(QVariant object,QString &output);

    public:
	    bool serialize;
    };
}

#endif /* QT_JSUTIL_H_ */