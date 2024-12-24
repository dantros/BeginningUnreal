// Tutorial 4D Runtime

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "RedGem.generated.h"

UCLASS()
class BEGINNINGUNREAL_API ARedGem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARedGem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	TObjectPtr<USoundWave> SoundWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	float AngularSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	float InteractionDistance;
};
