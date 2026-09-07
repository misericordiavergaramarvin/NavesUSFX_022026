#include "Moneda.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AMoneda::AMoneda()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = CollisionComp;
	CollisionComp->InitSphereRadius(60.0f);

	// 1. IMPORTANTE: Habilitar colisión para consultas y física
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComp->SetCollisionObjectType(ECC_WorldDynamic);

	// Permite detectar el Overlap con la nave
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	// Permite Bloquear disparos/objetos para activar el evento OnHit
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SphereMeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(SphereMeshAsset.Object);
		MeshComp->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	}
}

void AMoneda::BeginPlay()
{
	Super::BeginPlay();

	// Vincular ambos eventos de colisión
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AMoneda::OnOverlapBegin);
	CollisionComp->OnComponentHit.AddDynamic(this, &AMoneda::OnHit);
}

void AMoneda::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	// Si la nave (Pawn) la toca, la moneda cambia de lugar
	if (OtherActor && (OtherActor != this) && OtherActor->IsA(APawn::StaticClass()))
	{
		MoverAOTRALocalizacion();
	}
}

void AMoneda::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Si le impacta un disparo (o cualquier objeto distinto de la nave), se destruye
	if (OtherActor && (OtherActor != this))
	{
		Destroy();
	}
}

float AMoneda::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	Destroy();
	return DamageAmount;
}

void AMoneda::MoverAOTRALocalizacion()
{
	float XAleatoria = FMath::RandRange(-400.0f, 400.0f);
	float YAleatoria = FMath::RandRange(-400.0f, 400.0f);
	float ZFija = 200.0f;

	SetActorLocation(FVector(XAleatoria, YAleatoria, ZFija));
}