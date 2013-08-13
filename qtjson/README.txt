Using QtJson


JsObject *jso = new JsObject();
JsArray *jsa = new JsArray();

jsa->put("Apple");
jsa->put("Orange");

jso->setProperty("fruits",jsa);

jso->toString();