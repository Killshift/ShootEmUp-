// Test Project


#include "Components/STUHealthComponent.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All)

USTUHealthComponent::USTUHealthComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
	
}


void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	OnHealthChanged.Broadcast(Health);

	AActor* ComponentOwner = GetOwner();
	if(ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);
	}
	
}


void USTUHealthComponent::Regenerate(float HealUpdateTimeParameter, float HealModifierParameter)
{
	if (AutoHeal || GetWorld()->TimeSeconds - HealDelay > LastTakedDamageTime  || !IsDead() )
	{
		// ToDo реализовать логику регенерации
		// ToDo понять как вызывать регенерацию на тике

		// НО ЛУЧШЕ СДЕЛАТЬ КАК В ЛЕКЦИИ и не ебать мозг + научиться чему то новому

		UE_LOG(LogTemp, Warning, TEXT("Regenerating"));
	}

	UE_LOG(LogTemp, Warning, TEXT("TimeSeconds %f - HealDelay %f < LastTakedDamageTime %f"), GetWorld()->TimeSeconds, HealDelay, LastTakedDamageTime);
}

void USTUHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if( Damage <= 0 || IsDead() ) {return;}

	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

	LastTakedDamageTime = GetWorld()->TimeSeconds;
	UE_LOG(LogTemp, Warning, TEXT("Time is: %f "), LastTakedDamageTime);

	
		OnHealthChanged.Broadcast(Health);
	if(IsDead())
	{
		OnDeath.Broadcast();
	}
}

