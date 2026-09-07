// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef NAVESUSFX_022026_Moneda_generated_h
#error "Moneda.generated.h already included, missing '#pragma once' in Moneda.h"
#endif
#define NAVESUSFX_022026_Moneda_generated_h

#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_SPARSE_DATA
#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMoneda(); \
	friend struct Z_Construct_UClass_AMoneda_Statics; \
public: \
	DECLARE_CLASS(AMoneda, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NavesUSFX_022026"), NO_API) \
	DECLARE_SERIALIZER(AMoneda)


#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAMoneda(); \
	friend struct Z_Construct_UClass_AMoneda_Statics; \
public: \
	DECLARE_CLASS(AMoneda, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NavesUSFX_022026"), NO_API) \
	DECLARE_SERIALIZER(AMoneda)


#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMoneda(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMoneda) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMoneda); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMoneda); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMoneda(AMoneda&&); \
	NO_API AMoneda(const AMoneda&); \
public:


#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMoneda(AMoneda&&); \
	NO_API AMoneda(const AMoneda&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMoneda); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMoneda); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMoneda)


#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AMoneda, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__MeshComp() { return STRUCT_OFFSET(AMoneda, MeshComp); }


#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_10_PROLOG
#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_PRIVATE_PROPERTY_OFFSET \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_SPARSE_DATA \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_RPC_WRAPPERS \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_INCLASS \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_PRIVATE_PROPERTY_OFFSET \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_SPARSE_DATA \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_INCLASS_NO_PURE_DECLS \
	NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NAVESUSFX_022026_API UClass* StaticClass<class AMoneda>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NavesUSFX_022026_Source_NavesUSFX_022026_Moneda_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
