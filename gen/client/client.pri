QT += network

HEADERS += \
# Models
    $${PWD}/OAIBatteryStatus.h \
    $${PWD}/OAIBatteryStatusEvent.h \
    $${PWD}/OAICellularStatus.h \
    $${PWD}/OAICellularStatusEvent.h \
    $${PWD}/OAICloudConnector.h \
    $${PWD}/OAIConnectionLatency.h \
    $${PWD}/OAIConnectionLatencyEvent.h \
    $${PWD}/OAIConnectionStatus.h \
    $${PWD}/OAIConnectionStatusEvent.h \
    $${PWD}/OAIDataConnector.h \
    $${PWD}/OAIDataConnectorMessage.h \
    $${PWD}/OAIDataConnectorMetrics.h \
    $${PWD}/OAIDataConnector_httpConfig.h \
    $${PWD}/OAIDevice.h \
    $${PWD}/OAIErrorMessage.h \
    $${PWD}/OAIEthernetStatus.h \
    $${PWD}/OAIEthernetStatusEvent.h \
    $${PWD}/OAIEvent.h \
    $${PWD}/OAIEventType.h \
    $${PWD}/OAIInline_object.h \
    $${PWD}/OAIInline_object_1.h \
    $${PWD}/OAIInline_object_2.h \
    $${PWD}/OAIInline_object_3.h \
    $${PWD}/OAIInline_response_200.h \
    $${PWD}/OAIInline_response_200_1.h \
    $${PWD}/OAIInline_response_200_10.h \
    $${PWD}/OAIInline_response_200_11.h \
    $${PWD}/OAIInline_response_200_12.h \
    $${PWD}/OAIInline_response_200_13.h \
    $${PWD}/OAIInline_response_200_1_batchErrors.h \
    $${PWD}/OAIInline_response_200_2.h \
    $${PWD}/OAIInline_response_200_3.h \
    $${PWD}/OAIInline_response_200_4.h \
    $${PWD}/OAIInline_response_200_5.h \
    $${PWD}/OAIInline_response_200_6.h \
    $${PWD}/OAIInline_response_200_7.h \
    $${PWD}/OAIInline_response_200_8.h \
    $${PWD}/OAIInline_response_200_9.h \
    $${PWD}/OAILabel.h \
    $${PWD}/OAILabelsChangedEvent.h \
    $${PWD}/OAIMember.h \
    $${PWD}/OAINetworkStatus.h \
    $${PWD}/OAINetworkStatusCloudConnector.h \
    $${PWD}/OAINetworkStatusEvent.h \
    $${PWD}/OAIObjectPresent.h \
    $${PWD}/OAIObjectPresentEvent.h \
    $${PWD}/OAIOrganization.h \
    $${PWD}/OAIOrganizationPermissionList.h \
    $${PWD}/OAIProject.h \
    $${PWD}/OAIProjectPermissionList.h \
    $${PWD}/OAIProximitySensor.h \
    $${PWD}/OAIRole.h \
    $${PWD}/OAIServiceAccount.h \
    $${PWD}/OAIServiceAccountKey.h \
    $${PWD}/OAIServiceAccountKeyWithSecret.h \
    $${PWD}/OAIStatus.h \
    $${PWD}/OAITemperature.h \
    $${PWD}/OAITemperatureEvent.h \
    $${PWD}/OAITemperatureSensor.h \
    $${PWD}/OAITimeseries.h \
    $${PWD}/OAITouch.h \
    $${PWD}/OAITouchEvent.h \
    $${PWD}/OAITouchSensor.h \
# APIs
    $${PWD}/OAIDataConnectorsApi.h \
    $${PWD}/OAIDevicesApi.h \
    $${PWD}/OAIEventHistoryApi.h \
    $${PWD}/OAILiveEventsStreamingAPIApi.h \
    $${PWD}/OAIMembershipsAndAccessControlApi.h \
    $${PWD}/OAIOrganizationAndProjectsApi.h \
    $${PWD}/OAIServiceAccountsApi.h \
# Others
    $${PWD}/OAIHelpers.h \
    $${PWD}/OAIHttpRequest.h \
    $${PWD}/OAIObject.h
    $${PWD}/OAIEnum.h    

SOURCES += \
# Models
    $${PWD}/OAIBatteryStatus.cpp \
    $${PWD}/OAIBatteryStatusEvent.cpp \
    $${PWD}/OAICellularStatus.cpp \
    $${PWD}/OAICellularStatusEvent.cpp \
    $${PWD}/OAICloudConnector.cpp \
    $${PWD}/OAIConnectionLatency.cpp \
    $${PWD}/OAIConnectionLatencyEvent.cpp \
    $${PWD}/OAIConnectionStatus.cpp \
    $${PWD}/OAIConnectionStatusEvent.cpp \
    $${PWD}/OAIDataConnector.cpp \
    $${PWD}/OAIDataConnectorMessage.cpp \
    $${PWD}/OAIDataConnectorMetrics.cpp \
    $${PWD}/OAIDataConnector_httpConfig.cpp \
    $${PWD}/OAIDevice.cpp \
    $${PWD}/OAIErrorMessage.cpp \
    $${PWD}/OAIEthernetStatus.cpp \
    $${PWD}/OAIEthernetStatusEvent.cpp \
    $${PWD}/OAIEvent.cpp \
    $${PWD}/OAIEventType.cpp \
    $${PWD}/OAIInline_object.cpp \
    $${PWD}/OAIInline_object_1.cpp \
    $${PWD}/OAIInline_object_2.cpp \
    $${PWD}/OAIInline_object_3.cpp \
    $${PWD}/OAIInline_response_200.cpp \
    $${PWD}/OAIInline_response_200_1.cpp \
    $${PWD}/OAIInline_response_200_10.cpp \
    $${PWD}/OAIInline_response_200_11.cpp \
    $${PWD}/OAIInline_response_200_12.cpp \
    $${PWD}/OAIInline_response_200_13.cpp \
    $${PWD}/OAIInline_response_200_1_batchErrors.cpp \
    $${PWD}/OAIInline_response_200_2.cpp \
    $${PWD}/OAIInline_response_200_3.cpp \
    $${PWD}/OAIInline_response_200_4.cpp \
    $${PWD}/OAIInline_response_200_5.cpp \
    $${PWD}/OAIInline_response_200_6.cpp \
    $${PWD}/OAIInline_response_200_7.cpp \
    $${PWD}/OAIInline_response_200_8.cpp \
    $${PWD}/OAIInline_response_200_9.cpp \
    $${PWD}/OAILabel.cpp \
    $${PWD}/OAILabelsChangedEvent.cpp \
    $${PWD}/OAIMember.cpp \
    $${PWD}/OAINetworkStatus.cpp \
    $${PWD}/OAINetworkStatusCloudConnector.cpp \
    $${PWD}/OAINetworkStatusEvent.cpp \
    $${PWD}/OAIObjectPresent.cpp \
    $${PWD}/OAIObjectPresentEvent.cpp \
    $${PWD}/OAIOrganization.cpp \
    $${PWD}/OAIOrganizationPermissionList.cpp \
    $${PWD}/OAIProject.cpp \
    $${PWD}/OAIProjectPermissionList.cpp \
    $${PWD}/OAIProximitySensor.cpp \
    $${PWD}/OAIRole.cpp \
    $${PWD}/OAIServiceAccount.cpp \
    $${PWD}/OAIServiceAccountKey.cpp \
    $${PWD}/OAIServiceAccountKeyWithSecret.cpp \
    $${PWD}/OAIStatus.cpp \
    $${PWD}/OAITemperature.cpp \
    $${PWD}/OAITemperatureEvent.cpp \
    $${PWD}/OAITemperatureSensor.cpp \
    $${PWD}/OAITimeseries.cpp \
    $${PWD}/OAITouch.cpp \
    $${PWD}/OAITouchEvent.cpp \
    $${PWD}/OAITouchSensor.cpp \
# APIs
    $${PWD}/OAIDataConnectorsApi.cpp \
    $${PWD}/OAIDevicesApi.cpp \
    $${PWD}/OAIEventHistoryApi.cpp \
    $${PWD}/OAILiveEventsStreamingAPIApi.cpp \
    $${PWD}/OAIMembershipsAndAccessControlApi.cpp \
    $${PWD}/OAIOrganizationAndProjectsApi.cpp \
    $${PWD}/OAIServiceAccountsApi.cpp \
# Others
    $${PWD}/OAIHelpers.cpp \
    $${PWD}/OAIHttpRequest.cpp
