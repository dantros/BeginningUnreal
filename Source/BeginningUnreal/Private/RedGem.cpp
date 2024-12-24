// Tutorial 4D Runtime


#include "RedGem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARedGem::ARedGem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TObjectPtr<USceneComponent> Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(GetRootComponent());
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshResource(TEXT("/Script/Engine.StaticMesh'/Game/Assets/Gem/SM_Gem_Marquise_Red.SM_Gem_Marquise_Red'"));
	StaticMesh = StaticMeshResource.Object;
	StaticMeshComponent->SetStaticMesh(StaticMesh);

	FTransform Transform(FRotator(0, 0, 90), FVector(0, 0, 75), FVector(20, 20, 20));
	StaticMeshComponent->SetWorldTransform(Transform);

	ConstructorHelpers::FObjectFinder<USoundWave> SoundWaveResource(TEXT("/Script/Engine.SoundWave'/Game/Assets/Retro_PickUp_Coin_07.Retro_PickUp_Coin_07'"));
	SoundWave = SoundWaveResource.Object;

	AngularSpeed = 50.f;
	InteractionDistance = 300.f;
}

// Called when the game starts or when spawned
void ARedGem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARedGem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rotator = GetActorRotation();
	Rotator.Yaw += AngularSpeed * DeltaTime;

	SetActorRotation(Rotator);

	TObjectPtr<APawn> Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	FVector PlayerLocation = Pawn->GetActorLocation();
	FVector GemLocation = GetActorLocation();

	if (FVector::Distance(PlayerLocation, GemLocation) < InteractionDistance)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("C++ Collision!"));
		UE_LOG(LogTemp, Log, TEXT("C++ Collision!"));
		UGameplayStatics::PlaySound2D(GetWorld(), SoundWave);
		Destroy();
	}

}

