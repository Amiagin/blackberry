Using QtJson
Similar to gson and android's json. It's a bit easier to use.

#include "JsObject.h"
#include "JsArray.h"

using namespace QtJson;

JsObject *jso = new JsObject(); 
JsArray *jsa = new JsArray();   

jsa->put("Apple");
jsa->put("Orange");

jso->setProperty("fruits",jsa);

jso->toString();