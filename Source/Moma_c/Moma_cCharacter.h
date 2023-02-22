// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Moma_cCharacter.generated.h"


UCLASS(config=Game)
class AMoma_cCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

public:
	AMoma_cCharacter();
	
	virtual void Tick(float DeltaSeconds) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:
	void One();
	void Two();
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movements")
	bool bGo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movements")
	bool bArrive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movements")
	int32 CurrentBoard;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movements")
	int32 DestBoard;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movements")
	class AMainBoard* BoardObj;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Possession")
	int32 Possession;


public:
	void Go(int Num);

	UFUNCTION(Server, Reliable)
	void ReqBuyCity(FST_City CurCity);

	UFUNCTION(NetMulticast, Reliable)
	void ResBuyCity(FST_City CurCity);

public:
	FORCEINLINE void SetCurrentBoard(AMainBoard* CurBoard) { BoardObj = CurBoard; }

};

