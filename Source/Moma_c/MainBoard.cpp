// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBoard.h"
#include "Kismet/KismetMathLibrary.h"
#include "MGameInstance.h"
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
	Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
	Material = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Material/LandColor_Inst.LandColor_Inst'"));


	Board->SetStaticMesh(Mesh);


	FName ParameterName = FName("ColorParameterName");

	//FLinearColor NewParameterValue = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f); // Red color

	FVector ChangeColor = FVector(FMath::Lerp(PrevColor.X, NextColor.X, RunningTime), FMath::Lerp(PrevColor.Y, NextColor.Y, RunningTime), FMath::Lerp(PrevColor.Z, NextColor.Z, RunningTime));

	Board->SetVectorParameterValueOnMaterials(ParameterName,ChangeColor);

	Black = FVector(0,0,0);
	SkyBlue = FVector(0.1,0.3,0.5);
	Blue =  FVector(0,0,1);
	Red = FVector(1,0,0);
	Purple = FVector(0.3,0.1,0.7);
	Orange = FVector(0.8,0.3,0.2);
	Yellow = FVector(0.8,0.4,0);
	Green = FVector(0.1,0.8,0.1);
	White = FVector(1,1,1);
}

// Called when the game starts or when spawned
void AMainBoard::BeginPlay()
{
	Super::BeginPlay();

	Board->SetMaterial(0,Material);
	
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMainBoard::BoxBeginOverlap);

	UMGameInstance *gameInstance = Cast<UMGameInstance>(GetGameInstance());
	
	City = gameInstance->GetBoardRowData(CityRowName);

	if (City)
	{
		NewCityName = City->CityName;

		NewLandPrice = City->LandPrice;

		NewFirstPrice = City->FirstPrice;

		NewSecondPrice = City->SecondPrice;

		NewThirdPrice = City->ThirdPrice;

		NewLandMarkPrice = City->LandMarkPrice;


		
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("BoardFailed")));
	}

	if(City->Color == "Black")
	{
		 Board->SetVectorParameterValueOnMaterials(TEXT("Color"), Black);
	}
	else if(City->Color == "SkyBlue")
	{
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"), SkyBlue);

	}
	else if(City->Color == "White")
	{
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"), White);

	}
	else if(City->Color == "Blue")
	{
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"),Blue);
	}
	else if(City->Color == "Red")
	{		
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"), Red);

	}
	else if(City->Color == "Purple")
	{
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"), Purple);
	}
	else if(City->Color == "Orange")
	{
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"),Orange);
	}
	else if(City->Color == "Yellow")
	{
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"), Yellow);
	}
	else if(City->Color == "Green")
	{
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"), Green);
	}
	else
	{
		Board->SetVectorParameterValueOnMaterials(TEXT("Color"),FVector(0.9,0.4,0.2));
	}
	
	
	
	


	 
}

// Called every frame
void AMainBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// RunningTime += DeltaTime;

    // FVector ChangeColor = FVector(FMath::Lerp(PrevColor.X, NextColor.X, RunningTime), FMath::Lerp(PrevColor.Y, NextColor.Y, RunningTime), FMath::Lerp(PrevColor.Z, NextColor.Z, RunningTime));
   
 	// Board->SetVectorParameterValueOnMaterials(TEXT("Color"), FVector(0.1,0.3,0.5));

    // if (RunningTime >= 1.0f)
    // {
    //     PrevColor = NextColor;
    //     NextColor = FVector(FMath::RandRange(0.0f, 1.0f), FMath::RandRange(0.0f, 1.0f), FMath::RandRange(0.0f, 1.0f));
    //     RunningTime = 0.0f;
	// }


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
			Character->SetCurrentBoard(this);
			
			ArriveAtBoard();
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s: %d"),*NewCityName,NewLandPrice));
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

			/*FInputModeUIOnly UIMode;
			GetWorld()->GetFirstPlayerController()->SetInputMode(UIMode);
			GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);*/
		}
	}

}