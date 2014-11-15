#include <Python.h>

#include "sifcoin.h"

static PyObject *sifcoin_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    sifcoin_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    sifcoin_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef sifcoinMethods[] = {
    { "getPoWHash", sifcoin_getpowhash, METH_VARARGS, "Returns the proof of work hash using sifcoin hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef sifcoinModule = {
    PyModuleDef_HEAD_INIT,
    "sifcoin_hash",
    "...",
    -1,
    sifcoinMethods
};

PyMODINIT_FUNC PyInit_sifcoin_hash(void) {
    return PyModule_Create(&sifcoinModule);
}

#else

PyMODINIT_FUNC initsifcoin_hash(void) {
    (void) Py_InitModule("sifcoin_hash", sifcoinMethods);
}
#endif