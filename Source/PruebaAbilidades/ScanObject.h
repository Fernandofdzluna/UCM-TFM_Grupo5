// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScanableObject.h"
#include "Components/ActorComponent.h"
#include "ScanObject.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRUEBAABILIDADES_API UScanObject : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScanObject();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scan Properties")
	float Spawndistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scan Properties")
	TArray<AScanableObject*> SaveObject;
	UFUNCTION(BlueprintCallable, Category="Scan")
	const TArray<AScanableObject*>& GetSaveObject() const { return SaveObject; }

	UFUNCTION(BlueprintCallable, Category = "Scan Functions")
	bool ScanObject(AScanableObject* ActorToScan);

	UFUNCTION(BlueprintCallable, Category = "Scan Functions")
	AScanableObject* SpawnObject(AScanableObject* ActorToGet);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
