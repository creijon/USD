//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdGeom/pointInstancer.h"
#include "pxr/usd/usd/schemaBase.h"

#include "pxr/usd/sdf/primSpec.h"

#include "pxr/usd/usd/pyConversions.h"
#include "pxr/base/tf/pyContainerConversions.h"
#include "pxr/base/tf/pyResultConversions.h"
#include "pxr/base/tf/pyUtils.h"
#include "pxr/base/tf/wrapTypeHelpers.h"

#include "pxr/external/boost/python.hpp"

#include <string>

PXR_NAMESPACE_USING_DIRECTIVE

using namespace pxr_boost::python;

namespace {

#define WRAP_CUSTOM                                                     \
    template <class Cls> static void _CustomWrapCode(Cls &_class)

// fwd decl.
WRAP_CUSTOM;

        
static UsdAttribute
_CreateProtoIndicesAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateProtoIndicesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->IntArray), writeSparsely);
}
        
static UsdAttribute
_CreateIdsAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateIdsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int64Array), writeSparsely);
}
        
static UsdAttribute
_CreatePositionsAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreatePositionsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Point3fArray), writeSparsely);
}
        
static UsdAttribute
_CreateOrientationsAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateOrientationsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->QuathArray), writeSparsely);
}
        
static UsdAttribute
_CreateOrientationsfAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateOrientationsfAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->QuatfArray), writeSparsely);
}
        
static UsdAttribute
_CreateScalesAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateScalesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float3Array), writeSparsely);
}
        
static UsdAttribute
_CreateVelocitiesAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateVelocitiesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Vector3fArray), writeSparsely);
}
        
static UsdAttribute
_CreateAccelerationsAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateAccelerationsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Vector3fArray), writeSparsely);
}
        
static UsdAttribute
_CreateAngularVelocitiesAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateAngularVelocitiesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Vector3fArray), writeSparsely);
}
        
static UsdAttribute
_CreateInvisibleIdsAttr(UsdGeomPointInstancer &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateInvisibleIdsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int64Array), writeSparsely);
}

static std::string
_Repr(const UsdGeomPointInstancer &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdGeom.PointInstancer(%s)",
        primRepr.c_str());
}

} // anonymous namespace

void wrapUsdGeomPointInstancer()
{
    typedef UsdGeomPointInstancer This;

    class_<This, bases<UsdGeomBoundable> >
        cls("PointInstancer");

    cls
        .def(init<UsdPrim>(arg("prim")))
        .def(init<UsdSchemaBase const&>(arg("schemaObj")))
        .def(TfTypePythonClass())

        .def("Get", &This::Get, (arg("stage"), arg("path")))
        .staticmethod("Get")

        .def("Define", &This::Define, (arg("stage"), arg("path")))
        .staticmethod("Define")

        .def("GetSchemaAttributeNames",
             &This::GetSchemaAttributeNames,
             arg("includeInherited")=true,
             return_value_policy<TfPySequenceToList>())
        .staticmethod("GetSchemaAttributeNames")

        .def("_GetStaticTfType", (TfType const &(*)()) TfType::Find<This>,
             return_value_policy<return_by_value>())
        .staticmethod("_GetStaticTfType")

        .def(!self)

        
        .def("GetProtoIndicesAttr",
             &This::GetProtoIndicesAttr)
        .def("CreateProtoIndicesAttr",
             &_CreateProtoIndicesAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetIdsAttr",
             &This::GetIdsAttr)
        .def("CreateIdsAttr",
             &_CreateIdsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetPositionsAttr",
             &This::GetPositionsAttr)
        .def("CreatePositionsAttr",
             &_CreatePositionsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetOrientationsAttr",
             &This::GetOrientationsAttr)
        .def("CreateOrientationsAttr",
             &_CreateOrientationsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetOrientationsfAttr",
             &This::GetOrientationsfAttr)
        .def("CreateOrientationsfAttr",
             &_CreateOrientationsfAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetScalesAttr",
             &This::GetScalesAttr)
        .def("CreateScalesAttr",
             &_CreateScalesAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetVelocitiesAttr",
             &This::GetVelocitiesAttr)
        .def("CreateVelocitiesAttr",
             &_CreateVelocitiesAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetAccelerationsAttr",
             &This::GetAccelerationsAttr)
        .def("CreateAccelerationsAttr",
             &_CreateAccelerationsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetAngularVelocitiesAttr",
             &This::GetAngularVelocitiesAttr)
        .def("CreateAngularVelocitiesAttr",
             &_CreateAngularVelocitiesAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetInvisibleIdsAttr",
             &This::GetInvisibleIdsAttr)
        .def("CreateInvisibleIdsAttr",
             &_CreateInvisibleIdsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))

        
        .def("GetPrototypesRel",
             &This::GetPrototypesRel)
        .def("CreatePrototypesRel",
             &This::CreatePrototypesRel)
        .def("__repr__", ::_Repr)
    ;

    _CustomWrapCode(cls);
}

// ===================================================================== //
// Feel free to add custom code below this line, it will be preserved by 
// the code generator.  The entry point for your custom code should look
// minimally like the following:
//
// WRAP_CUSTOM {
//     _class
//         .def("MyCustomMethod", ...)
//     ;
// }
//
// Of course any other ancillary or support code may be provided.
// 
// Just remember to wrap code in the appropriate delimiters:
// 'namespace {', '}'.
//
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

#include "pxr/base/tf/pyEnum.h"

namespace {

static
pxr_boost::python::list
_ComputeMaskAtTime(const UsdGeomPointInstancer& self,
                   const UsdTimeCode time)
{
    pxr_boost::python::list items;
    for (const auto& b : self.ComputeMaskAtTime(time)) {
        items.append(static_cast<bool>(b));
    }

    return items;
}

static
VtMatrix4dArray
_ComputeInstanceTransformsAtTime(
    const UsdGeomPointInstancer& self,
    const UsdTimeCode time,
    const UsdTimeCode baseTime,
    const UsdGeomPointInstancer::ProtoXformInclusion doProtoXforms,
    const UsdGeomPointInstancer::MaskApplication applyMask)
{
    VtMatrix4dArray xforms;

    // On error we'll be returning an empty array.
    self.ComputeInstanceTransformsAtTime(&xforms, time, baseTime,
                                         doProtoXforms, applyMask);

    return xforms;
}

static
std::vector<VtMatrix4dArray>
_ComputeInstanceTransformsAtTimes(
    const UsdGeomPointInstancer& self,
    const std::vector<UsdTimeCode>& times,
    const UsdTimeCode baseTime,
    const UsdGeomPointInstancer::ProtoXformInclusion doProtoXforms,
    const UsdGeomPointInstancer::MaskApplication applyMask)
{
    std::vector<VtMatrix4dArray> xforms;

    // On error we'll be returning an empty array.
    self.ComputeInstanceTransformsAtTimes(&xforms, times, baseTime,
                                         doProtoXforms, applyMask);

    return xforms;
}

static
VtVec3fArray
_ComputeExtentAtTime(
    const UsdGeomPointInstancer& self,
    const UsdTimeCode time,
    const UsdTimeCode baseTime)
{
    VtVec3fArray extent;

    // On error we'll be returning an empty array.
    self.ComputeExtentAtTime(&extent, time, baseTime);

    return extent;
}

static
std::vector<VtVec3fArray>
_ComputeExtentAtTimes(
    const UsdGeomPointInstancer& self,
    const std::vector<UsdTimeCode>& times,
    const UsdTimeCode baseTime)
{
    std::vector<VtVec3fArray> extents;

    // On error we'll be returning an empty array.
    self.ComputeExtentAtTimes(&extents, times, baseTime);

    return extents;
}

WRAP_CUSTOM {

    typedef UsdGeomPointInstancer This;

    // class needs to be in-scope for enums to get wrapped properly
    scope obj = _class;

    TfPyWrapEnum<This::MaskApplication>();

    TfPyWrapEnum<This::ProtoXformInclusion>();

    _class
        .def("ActivateId", 
             &This::ActivateId,
             (arg("id")))
        .def("ActivateIds", 
             &This::ActivateIds,
             (arg("ids")))
        .def("ActivateAllIds", 
             &This::ActivateAllIds)
        .def("DeactivateId", 
             &This::DeactivateId,
             (arg("id")))
        .def("DeactivateIds", 
             &This::DeactivateIds,
             (arg("ids")))

        .def("VisId", 
             &This::VisId,
             (arg("id"), arg("time")))
        .def("VisIds", 
             &This::VisIds,
             (arg("ids"), arg("time")))
        .def("VisAllIds", 
             &This::VisAllIds,
             (arg("time")))
        .def("InvisId", 
             &This::InvisId,
             (arg("id"), arg("time")))
        .def("InvisIds", 
             &This::InvisIds,
             (arg("ids"), arg("time")))
        
        // The cost to fetch 'ids' is likely dwarfed by python marshalling
        // costs, so let's not worry about the 'ids' optional arg
        .def("ComputeMaskAtTime",
             &_ComputeMaskAtTime,
             (arg("time")))

        .def("ComputeInstanceTransformsAtTime",
             &_ComputeInstanceTransformsAtTime,
             (arg("time"), arg("baseTime"),
              arg("doProtoXforms")=This::IncludeProtoXform,
              arg("applyMask")=This::ApplyMask))
        .def("ComputeInstanceTransformsAtTimes",
             &_ComputeInstanceTransformsAtTimes,
             (arg("times"), arg("baseTime"),
              arg("doProtoXforms")=This::IncludeProtoXform,
              arg("applyMask")=This::ApplyMask))

        .def("ComputeExtentAtTime",
             &_ComputeExtentAtTime,
             (arg("time"), arg("baseTime")))
        .def("ComputeExtentAtTimes",
             &_ComputeExtentAtTimes,
             (arg("times"), arg("baseTime")))

        .def("GetInstanceCount", &UsdGeomPointInstancer::GetInstanceCount,
            arg("timeCode")=UsdTimeCode::Default()) 
        ;
    TfPyRegisterStlSequencesFromPython<UsdTimeCode>();
    to_python_converter<std::vector<VtArray<GfMatrix4d>>,
        TfPySequenceToPython<std::vector<VtArray<GfMatrix4d>>>>();
    to_python_converter<std::vector<VtVec3fArray>,
        TfPySequenceToPython<std::vector<VtVec3fArray>>>();
}

} // anonymous namespace
