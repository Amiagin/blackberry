/*
 * Version: 0.1
 * Git https://github.com/Amiagin/blackberry/qtjson
 *
 * JsObject.h
 *
 *  Created on: Mar 22, 2013
 *      Author: Christopher.D
 */

#ifndef QT_JSOBJECT_H_
#define QT_JSOBJECT_H_

#include <bb/data/JsonDataAccess>
#include "JsArray.h"

namespace QtJson{
    class JsArray;

    class JsObject : public JsUtil {
        private:
	        QVariantMap qtObject;
	        bool error;

        public:
	        JsObject();
	        JsObject(QString data);
	        JsObject(QVariant qtObject);
	        virtual ~JsObject();

	        bool has(QString key);
	        JsObject *getObject(QString key);
	        JsArray *getArray(QString key);

	        int getNumber(QString key);
	        QString getString(QString key);

	        void setProperty(QString key, QString value);
	        void setProperty(QString key, int value);
	        void setProperty(QString key, double value);
	        void setProperty(QString key, qlonglong value);
	        void setProperty(QString key, JsObject *object);
	        void setProperty(QString key, JsArray *array);

	        QVariant getJsObject();

	        QString toString();

	        bool hasError();
    };
}

#endif /* QT_JSOBJECT_H_ */
