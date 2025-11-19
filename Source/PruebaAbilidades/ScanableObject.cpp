// Fill out your copyright notice in the Description page of Project Settings.


#include "ScanableObject.h"

// Sets default values
AScanableObject::AScanableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScanableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScanableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

