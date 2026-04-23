// Gabriel Mosz All Rights Reserved


#include "Anim/Hero/VarvaraLinkedAnimLayer.h"

#include "Anim/Hero/VarvaraAnimInstance.h"

UVarvaraAnimInstance* UVarvaraLinkedAnimLayer::GetVarvaraAnimInstance() const
{
	return Cast<UVarvaraAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
