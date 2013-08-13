/*
 * Version: 0.1
 * Git https://github.com/Amiagin/blackberry/qtjson
 *
 * JsArray.h
 *
 *  Created on: Mar 22, 2013
 *      Author: Christopher.D
 */

#ifndef QT_JSARRAY_H_
#define QT_JSARRAY_H_

#include <bb/data/JsonDataAccess>

#include "JsUtil.h"
#include "JsObject.h"

namespace QtJson {
    class JsObject;

    class JsArray : public JsUtil {
        private:
	        QVariantList qtObject;
        public:
	        JsArray();
	        JsArray(QVariant qtObject);
	        virtual ~JsArray();

	        JsObject *getObject(int index);
	        QVariant getArray();

	        int size();

	        void put(QVariant value);
	        void put(JsObject *object);
    };
}

#endif /* QT_JSARRAY_H_ */
