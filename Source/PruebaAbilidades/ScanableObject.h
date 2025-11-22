// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScanableObject.generated.h"

UCLASS()
class PRUEBAABILIDADES_API AScanableObject : public AActor
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	AScanableObject();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scan Properties")
	FString ScanName;
	UFUNCTION(BlueprintCallable, Category = "Scan Properties")
	const FString& GetScanName() const { return ScanName; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
