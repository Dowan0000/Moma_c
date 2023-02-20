// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FST_City.h"
#include "MainBoard.generated.h"

UCLASS()
class MOMA_C_API AMainBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void BoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintNativeEvent)
	void RotationCharacter();

	UFUNCTION(BlueprintNativeEvent)
	void ArriveAtBoard();


	

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Board;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class AMoma_cCharacter* Character;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> ArriveWidgetClass;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UUserWidget* ArriveWidget;

	FST_City* City;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CityInformaition", meta = (AllowPrivateAccess = "true"))
	int32 CityRowName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CityInformaition", meta = (AllowPrivateAccess = "true"))
	int32 NewLandPrice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CityInformaition", meta = (AllowPrivateAccess = "true"))
	int32 NewFirstPrice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CityInformaition", meta = (AllowPrivateAccess = "true"))
	int32 NewSecondPrice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CityInformaition", meta = (AllowPrivateAccess = "true"))
	int32 NewThirdPrice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CityInformaition", meta = (AllowPrivateAccess = "true"))
	int32 NewLandMarkPrice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CityInformaition", meta = (AllowPrivateAccess = "true"))
	FString NewCityName;


	


	
	


};
