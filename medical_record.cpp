#include "medical_record.h"
#include "libs.h"

char* myStrcpy(char* destination, const char* source) {
    char* originalDestination = destination; 
    while (*source != '\0') { 
        *destination = *source; 
        destination++;
        source++; 
    }

    *destination = '\0'; 
    return originalDestination; 
}


MedicalRecord::MedicalRecord(const char* diseaseName, const char* treatmentPlan, const char* diagnosisDate, const char* doctorID) {
    try {
        _diseaseName = new char[strlen(diseaseName) + 1];
        myStrcpy(_diseaseName, diseaseName);
        _treatmentPlan = new char[strlen(treatmentPlan) + 1];
        myStrcpy(_treatmentPlan, treatmentPlan);
        _diagnosisDate = new char[strlen(diagnosisDate) + 1];
        myStrcpy(_diagnosisDate, diagnosisDate);
        _doctorID = new char[strlen(doctorID) + 1];
        myStrcpy(_doctorID, doctorID);
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw; 
    }
}

MedicalRecord::~MedicalRecord() {
    delete[] _diseaseName;
    delete[] _treatmentPlan;
    delete[] _diagnosisDate;
    delete[] _doctorID;
}
void MedicalRecord::displayAppointment() const {
    cout << "\tPatientID: " << _diseaseName << endl;
    cout << "\tDoctorID: " << _treatmentPlan << endl;
    cout << "\tAppointmentDate: " << _diagnosisDate << endl;
    cout << "\tNotes: " << _doctorID << endl;
}