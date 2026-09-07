// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class NAVESUSFX_022026_API AEnemigo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Componentes del enemigo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	class UStaticMeshComponent* MallaEnemigo;

	// Variables para controlar el movimiento continuo
	FVector DireccionMovimiento;
	float Velocidad;
	
	// Límites de desplazamiento en el escenario (Ejes X e Y)
	float LimiteX;
	float LimiteY;

	// Posición inicial para controlar el rango de patrulla
	FVector PosicionInicial;


};
