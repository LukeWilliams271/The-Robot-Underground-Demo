// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TempCPU.h"


#include "Robot.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRUDEMO_API URobot : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URobot();

	UPROPERTY(EditAnywhere, Category = "Core Data")
	float moveSpeed;
	UPROPERTY(EditAnywhere, Category = "Core Data")
	AActor* CPUObj;
	UPROPERTY(EditAnywhere, Category = "Core Data")
	int drivebasePinNum = 1;
	UPROPERTY(VisibleAnywhere, Category = "Derived Data")
	float sigSpeedMult;
	UPROPERTY(VisibleAnywhere, Category = "Derived Data")
	AActor* self;
	UPROPERTY(VisibleAnywhere, Category = "Derived Data")
	int tick = 0;
	UPROPERTY(VisibleAnywhere, Category = "Derived Data")
	bool go = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	float ToSpeedDCMotor(int input, float avg);
	UFUNCTION(BlueprintCallable)
	void SetGo();
};
