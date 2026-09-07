#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moneda.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class NAVESUSFX_022026_API AMoneda : public AActor
{
	GENERATED_BODY()

public:
	AMoneda();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* MeshComp;

	// Evento de Superposición (Tocada por la nave)
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	// Evento de Impacto (Chocada por el disparo)
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	void MoverAOTRALocalizacion();
};