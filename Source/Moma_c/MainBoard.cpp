// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBoard.h"
#include "Components/BoxComponent.h"
#include "Moma_cCharacter.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AMainBoard::AMainBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Board = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Board"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

	//Board->SetupAttachment(RootComponent);
	SetRootComponent(Board);
	CollisionBox->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AMainBoard::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMainBoard::BoxBeginOverlap);

}

// Called every frame
void AMainBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainBoard::BoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!Character) Character = Cast<AMoma_cCharacter>(OtherActor);

	if (Character)
	{
		Character->CurrentBoard += 1;
		
		if (Character->CurrentBoard == Character->DestBoard)
		{
			Character->bArrive = true;
			ArriveAtBoard();
		}
	}

	RotationCharacter();
}

void AMainBoard::RotationCharacter_Implementation()
{

}

void AMainBoard::ArriveAtBoard_Implementation()
{
	if (ArriveWidgetClass)
	{
		ArriveWidget = CreateWidget<UUserWidget>(GetWorld(), ArriveWidgetClass);
		
		if (ArriveWidget)
		{
			ArriveWidget->AddToViewport();

			FInputModeUIOnly UIMode;
			GetWorld()->GetFirstPlayerController()->SetInputMode(UIMode);
			GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
		}
	}
}