// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Crear el componente de malla estática
	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim_90_In.Shape_Trim_90_In'"));
	RootComponent = MallaEnemigo;

	// 2. Buscar y cargar el StaticMesh desde el StarterContent
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Trim_90_In.Shape_Trim_90_In"));

	// 3. Verificar que el asset exista antes de asignarlo
	if (MeshAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MeshAsset.Object);
	}

	// Configuración básica de velocidad y movimiento
	Velocidad = 300.0f;
	LimiteX = 600.0f;
	LimiteY = 600.0f;
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
	// Guardar la posición inicial en la que hizo Spawn
	PosicionInicial = GetActorLocation();

	// Asignar una velocidad y dirección aleatoria a cada enemigo
	Velocidad = FMath::RandRange(200.0f, 500.0f);

	// Generar un vector de dirección aleatorio en el plano X e Y
	float RandomX = FMath::RandRange(-1.0f, 1.0f);
	float RandomY = FMath::RandRange(-1.0f, 1.0f);
	DireccionMovimiento = FVector(RandomX, RandomY, 0.0f).GetSafeNormal();
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Mover el actor en la dirección configurada
	FVector PosicionActual = GetActorLocation();
	FVector NuevaPosicion = PosicionActual + (DireccionMovimiento * Velocidad * DeltaTime);
	SetActorLocation(NuevaPosicion);

	// Rebotar o invertir dirección si se aleja demasiado de su punto de origen (Eje X)
	if (FMath::Abs(NuevaPosicion.X - PosicionInicial.X) > LimiteX)
	{
		DireccionMovimiento.X *= -1.0f;
	}

	// Rebotar o invertir dirección si se aleja demasiado de su punto de origen (Eje Y)
	if (FMath::Abs(NuevaPosicion.Y - PosicionInicial.Y) > LimiteY)
	{
		DireccionMovimiento.Y *= -1.0f;
	}
}

