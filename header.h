
@class NSTimer, NSDictionary;

@interface SBMediaController : NSObject {
	int _manualVolumeChangeCount;
	NSDictionary* _nowPlayingInfo;
	float _pendingVolumeChange;
	NSTimer* _volumeCommitTimer;
	BOOL _debounceVolumeRepeat;
}
+(id)sharedInstance;
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(void)setNowPlayingInfo:(id)info;
-(BOOL)hasTrack;
-(BOOL)isFirstTrack;
-(BOOL)isLastTrack;
-(BOOL)isPlaying;
-(BOOL)isMovie;
-(BOOL)isTVOut;
-(id)nowPlayingArtist;
-(id)nowPlayingTitle;
-(id)nowPlayingAlbum;
-(BOOL)changeTrack:(int)track;
-(BOOL)beginSeek:(int)seek;
-(BOOL)endSeek:(int)seek;
-(BOOL)togglePlayPause;
-(float)volume;
-(void)setVolume:(float)volume;
-(void)_changeVolumeBy:(float)by;
-(float)_calcButtonRepeatDelay;
-(void)increaseVolume;
-(void)decreaseVolume;
-(void)cancelVolumeEvent;
//-(void)handleVolumeEvent:(GSEventRef)event;
-(void)_registerForAVSystemControllerNotifications;
-(void)_unregisterForAVSystemControllerNotifications;
-(void)_serverConnectionDied:(id)died;
-(void)_systemVolumeChanged:(id)changed;
-(void)_cancelPendingVolumeChange;
-(void)_commitVolumeChange:(id)change;
-(void)_delayedExtendSleepTimer;
@end
/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */



@class NSMutableDictionary, NSTimer;

@interface SBWiFiManager : NSObject {
//	WiFiManagerClient* _manager;
//	WiFiDeviceClient* _device;
//	WiFiNetwork* _currentNetwork;
	BOOL _currentNetworkHasBeenSet;
	BOOL _powered;
	BOOL _poweredHasBeenSet;
	int _rssiThreshold;
	BOOL _joining;
	int _signalStrengthBars;
	BOOL _signalStrengthHasBeenSet;
	NSTimer* _signalStrengthTimer;
	int _shouldPollSignalStrength;
	BOOL _canPollSignalStrength;
#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
	NSMutableDictionary* _securityDict;
#endif
	id _delegate;
	unsigned _notificationID;
	double _lastSignalStrengthUpdateTime;
}
+(id)sharedInstance;
-(BOOL)wiFiEnabled;
-(void)setWiFiEnabled:(BOOL)enabled;
-(int)signalStrengthBars;
-(void)updateSignalStrength;
-(void)_updateSignalStrengthTimer;
-(void)beginPollingForSignalStrength;
-(void)endPollingForSignalStrength;
-(void)cancelTrust:(BOOL)trust;
-(void)acceptTrust:(id)trust;
-(void)cancelPicker:(BOOL)picker;
-(void)userChoseNetwork:(id)network;
-(id)knownNetworks;
#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
-(BOOL)networkRequiresPassword:(id)password;
#endif
-(void)resetSettings;
-(void)_scanComplete:(CFArrayRef)complete;
//-(void)_joinComplete:(int)complete network:(WiFiNetwork*)network;
-(void)joinNetwork:(id)network password:(id)password;
-(void)_askToJoinWithID:(unsigned)anId;
//-(void)_trustCallbackWithID:(unsigned)anId type:(int)type network:(WiFiNetwork*)network data:(id)data;
@end

/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

//#import "RadiosPreferencesDelegate.h"
//#import <XXUnknownSuperclass.h> // Unknown library
//#import "Springboard-Structs.h"

@class RadiosPreferences, NSString, NSTimer, SBAlertItem;

@interface SBTelephonyManager : NSObject {
	void* _suspendDormancyAssertion;
	NSString* _operatorName;
	NSString* _lastKnownNetworkCountryCode;
	unsigned _suspendDormancyEnabled;
	unsigned _usingWifi : 1;
	unsigned _usingVPN : 1;
	unsigned _iTunesNeedsToRecheckActivation : 1;
	unsigned _pretendingToSearch : 1;
	unsigned _callForwardingIndicator : 2;
	BOOL _isNetworkTethering;
	int _numberOfNetworkTetheredDevices;
	unsigned _hasShownWaitingAlert : 1;
	SBAlertItem* _activationAlertItem;
	int _numActivationFailures;
	unsigned _loggingCallAudio : 1;
	NSString* _inCallStatusPreamble;
	NSTimer* _inCallTimer;
	RadiosPreferences* _radioPrefs;
	int _needsUserIdentificationModule;
}
+(id)sharedTelephonyManager;
+(id)sharedTelephonyManagerCreatingIfNecessary:(BOOL)necessary;
-(id)init;
-(void)_postStartupNotification;
//-(CTServerConnectionRef)_serverConnection;
-(void)_avSystemControllerDidError:(id)_avSystemController;
//-(void)_serverConnectionDidError:(XXStruct_K5nmsA)_serverConnection;
-(void)SBTelephonyDaemonRestartHandler;
-(void)updateTTYIndicator;
-(double)inCallDuration;
-(void)setCallForwardingIndicator:(int)indicator;
-(void)updateCallForwardingIndicator;
-(int)callForwardingIndicator;
-(void)updateSpringBoard;
-(void)updateStatusBarCallState:(BOOL)state;
-(void)updateStatusBarCallDuration;
-(void)setLimitTransmitPowerPerBandEnabled:(BOOL)enabled;
-(void)setFastDormancySuspended:(BOOL)suspended;
-(void)updateAirplaneMode;
-(void)airplaneModeChanged;
-(void)updateCalls;
-(void)_updateState;
-(BOOL)updateLocale;
-(BOOL)updateNetworkLocale;
-(BOOL)_updateLastKnownNetworkCountryCode;
-(id)lastKnownNetworkCountryCode;
-(void)handleSIMReady;
-(id)urlWithScheme:(id)scheme fromDialingNumber:(id)dialingNumber abUID:(int)uid urlPathAddition:(id)addition forceAssist:(BOOL)assist suppressAssist:(BOOL)assist6 wasAlreadyAssisted:(BOOL)assisted;
-(id)displayForOutgoingCallURL:(id)outgoingCallURL;
-(void)_delayedAudioResume;
-(long long)getRowIDOfLastCallInsert;
-(id)allMissedCallsAfterRowID:(long long)anId;
-(int)callCount;
-(BOOL)activeCallExists;
-(BOOL)heldCallExists;
-(BOOL)incomingCallExists;
-(BOOL)outgoingCallExists;
-(BOOL)multipleCallsExist;
-(BOOL)inCallUsingReceiverForcingRoutingToReceiver:(BOOL)receiver;
-(BOOL)callWouldUseReceiver:(BOOL)receiver;
-(BOOL)shouldHangUpOnLock;
-(BOOL)inCall;
-(void)disconnectIncomingCall;
-(BOOL)isCallAmbiguous;
-(void)swapCalls;
-(void)disconnectAllCalls;
-(void)disconnectCall;
-(void)disconnectCallAndActivateHeld;
-(void)unmute;
-(void)setIncomingVoiceCallsEnabled:(BOOL)enabled;
-(BOOL)isLoggingCallAudio;
-(void)_setIsLoggingCallAudio:(BOOL)audio;
-(void)dumpBasebandState:(id)state;
-(BOOL)MALoggingEnabled;
-(BOOL)isNetworkRegistrationEnabled;
-(void)setNetworkRegistrationEnabled:(BOOL)enabled;
-(int)dataConnectionType;
-(BOOL)cellularRadioCapabilityIsActive;
-(BOOL)EDGEIsOn;
-(id)_radioPrefs;
-(void)setIsInAirplaneMode:(BOOL)airplaneMode;
-(BOOL)isInAirplaneMode;
-(BOOL)isUsingSlowDataConnection;
-(BOOL)isTTYEnabled;
-(void)setIsUsingWiFiConnection:(BOOL)connection;
-(void)setIsUsingVPNConnection:(BOOL)connection;
-(BOOL)isUsingVPNConnection;
-(void)_postDataConnectionTypeChangedNotification;
-(id)copyMobileEquipmentInfo;
-(id)copyTelephonyCapabilities;
-(void)_setCurrentActivationAlertItem:(id)item;
-(void)_provisioningUpdateWithStatus:(int)status;
-(BOOL)isEmergencyCallActive;
-(BOOL)isInEmergencyCallbackMode;
-(void)exitEmergencyCallbackMode;
-(void)configureForTTY:(BOOL)tty;
-(BOOL)shouldPromptForTTY;
-(id)ttyTitle;
-(void)_resetCTMMode;
-(void)_headphoneChanged:(id)changed;
-(void)_proximityChanged:(id)changed;
-(void)postponementStatusChanged;
-(void)_setRegistrationStatus:(int)status;
-(void)_updateRegistrationNow;
-(void)_cancelFakeService;
-(void)_startFakeServiceIfNecessary;
-(void)_stopFakeService;
-(BOOL)_pretendingToSearch;
-(void)_prepareToAnswerCall;
-(void)carrierBundleChanged;
-(id)_fetchOperatorName;
-(void)_reallySetOperatorName:(id)name;
-(void)setOperatorName:(id)name;
-(void)operatorBundleChanged;
-(id)operatorName;
-(int)registrationStatus;
-(BOOL)canOnlyMakeEmergencyCalls;
-(void)checkForRegistrationSoon;
-(id)SIMStatus;
-(BOOL)needsUserIdentificationModule;
-(int)registrationCauseCode;
-(void)noteSIMUnlockAttempt;
-(BOOL)isNetworkTethering;
-(int)numberOfNetworkTetheredDevices;
-(void)setIsNetworkTethering:(BOOL)tethering withNumberOfDevices:(int)devices;
-(void)noteWirelessModemChanged;
-(void)_wokeFromSleep:(id)sleep;
@end
/*
 *     Generated by class-dump 3.3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */


@class NSMutableDictionary;

@interface BluetoothManager : NSObject
{
    struct BTLocalDeviceImpl *_localDevice;
    struct BTSessionImpl *_session;
    int _available;
    BOOL _audioConnected;
    BOOL _scanningEnabled;
    BOOL _scanningInProgress;
    unsigned int _scanningServiceMask;
    struct BTDiscoveryAgentImpl *_discoveryAgent;
    struct BTPairingAgentImpl *_pairingAgent;
    struct BTAccessoryManagerImpl *_accessoryManager;
    NSMutableDictionary *_btAddrDict;
    NSMutableDictionary *_btDeviceDict;
    NSMutableDictionary *_seekingInProgressDict;
}

+ (id)sharedInstance;
+ (int)lastInitError;
- (BOOL)available;
- (id)init;
- (BOOL)_attach:(id)arg1;
- (BOOL)_setup:(struct BTSessionImpl *)arg1;
- (void)_cleanup:(BOOL)arg1;
- (void)dealloc;
- (void)_postNotificationWithArray:(id)arg1;
- (void)_postNotification:(id)arg1;
- (void)postNotification:(id)arg1;
- (void)postNotificationName:(id)arg1 object:(id)arg2;
- (void)postNotificationName:(id)arg1 object:(id)arg2 error:(id)arg3;
- (int)powerState;
- (BOOL)powered;
- (BOOL)enabled;
- (BOOL)setPowered:(BOOL)arg1;
- (BOOL)setEnabled:(BOOL)arg1;
- (void)_powerChanged;
- (BOOL)isAnyoneScanning;
- (id)addDeviceIfNeeded:(struct BTDeviceImpl *)arg1;
- (void)_removeDevice:(id)arg1;
- (BOOL)wasDeviceDiscovered:(id)arg1;
- (BOOL)deviceScanningEnabled;
- (BOOL)deviceScanningInProgress;
- (void)resetDeviceScanning;
- (void)_scanForServices:(unsigned int)arg1 withMode:(int)arg2;
- (void)scanForServices:(unsigned int)arg1;
- (void)scanForConnectableDevices:(unsigned int)arg1;
- (void)setDeviceScanningEnabled:(BOOL)arg1;
- (void)_restartScan;
- (void)_setScanState:(int)arg1;
- (void)_discoveryStateChanged;
- (BOOL)isDiscoverable;
- (void)setDiscoverable:(BOOL)arg1;
- (BOOL)devicePairingEnabled;
- (void)setDevicePairingEnabled:(BOOL)arg1;
- (void)cancelPairing;
- (void)unpairDevice:(id)arg1;
- (id)pairedDevices:(BOOL)arg1;
- (id)pairedDevices;
- (id)pairedLEDevices;
- (void)setPincode:(id)arg1 forDevice:(id)arg2;
- (void)acceptSSP:(int)arg1 forDevice:(id)arg2;
- (void)connectDevice:(id)arg1 withServices:(unsigned int)arg2;
- (void)connectDevice:(id)arg1;
- (BOOL)connectable;
- (void)setConnectable:(BOOL)arg1;
- (id)connectingDevices;
- (id)connectedDevices;
- (BOOL)_onlySensorsConnected;
- (BOOL)connected;
- (void)_connectedStatusChanged;
- (void)_connectabilityChanged;
- (BOOL)audioConnected;
- (void)setAudioConnected:(BOOL)arg1;
- (void)startVoiceCommand:(id)arg1;
- (void)endVoiceCommand:(id)arg1;
- (void)_sendSeekStart:(id)arg1 forDevice:(id)arg2;
- (void)_stopSeeking:(id)arg1 forDevice:(id)arg2;
- (void)sendContact:(id)arg1 toDevice:(id)arg2;
- (void)sendAllContactsToDevice:(id)arg1;
- (BOOL)isServiceSupported:(unsigned int)arg1;
- (void)enableTestMode;

@end

/**
 * This header is generated by class-dump-z 0.2b.
 *
 * Source: /System/Library/Frameworks/CoreLocation.framework/CoreLocation
 */



@class NSSet, CLHeading, NSString, CLLocation;
//@protocol CLLocationManagerDelegate;

@interface CLLocationManager : NSObject {
@private
	id _internal;
}
//@property(assign, nonatomic, getter=isLocationServicesPreferencesDialogEnabled) BOOL locationServicesPreferencesDialogEnabled;
@property(assign, nonatomic, getter=isPersistentMonitoringEnabled) BOOL persistentMonitoringEnabled;
//@property(readonly, assign, nonatomic) CLClientRef internalClient;
@property(readonly, assign, nonatomic) double bestAccuracy;
@property(assign, nonatomic) BOOL supportInfo;
@property(readonly, assign, nonatomic) double expectedGpsUpdateInterval;
@property(readonly, assign, nonatomic) BOOL locationServicesApproved;
@property(readonly, assign, nonatomic) BOOL locationServicesAvailable;
@property(assign, nonatomic) BOOL privateMode;
@property(readonly, assign, nonatomic) NSSet* monitoredRegions;
@property(readonly, assign, nonatomic) double maximumRegionMonitoringDistance;
@property(readonly, assign, nonatomic) CLHeading* heading;
@property(assign, nonatomic) int headingOrientation;
@property(assign, nonatomic) double headingFilter;
@property(readonly, assign, nonatomic) BOOL headingAvailable;
@property(readonly, assign, nonatomic) CLLocation* location;
@property(assign, nonatomic) double desiredAccuracy;
@property(assign, nonatomic) double distanceFilter;
@property(copy, nonatomic) NSString* purpose;
@property(readonly, assign, nonatomic) BOOL locationServicesEnabled;
//@property(assign, nonatomic) id<CLLocationManagerDelegate> delegate;
+(void)setDefaultEffectiveBundle:(id)bundle;
+(void)setDefaultEffectiveBundleIdentifier:(id)identifier;
+(void)setAuthorizationStatus:(BOOL)status forBundle:(id)bundle;
+(void)setAuthorizationStatus:(BOOL)status forBundleIdentifier:(id)bundleIdentifier;
+(int)authorizationStatus;
+(int)_authorizationStatus;
+(int)authorizationStatusForBundle:(id)bundle;
+(int)authorizationStatusForBundleIdentifier:(id)bundleIdentifier;
+(int)_authorizationStatusForBundleIdentifier:(id)bundleIdentifier bundle:(id)bundle;
+(BOOL)regionMonitoringEnabled;
+(BOOL)regionMonitoringAvailable;
+(BOOL)significantLocationChangeMonitoringAvailable;
+(BOOL)headingAvailable;
+(void)setLocationServicesEnabled:(BOOL)enabled;
+(BOOL)locationServicesEnabled:(BOOL)enabled;
+(BOOL)locationServicesEnabled;
+(id)sharedManager;
-(void)registerAsLocationClient;
-(void)onClientEventRegionSetupCompleted:(id)completed;
-(void)onClientEventRegionResponseDelayed:(id)delayed;
-(void)onClientEventRegionError:(id)error;
-(void)onClientEventRegion:(id)region;
-(void)onClientEventError:(id)error;
-(void)onClientEventHistoricLocation:(id)location;
-(void)onClientEventHeadingCalibration:(id)calibration;
-(void)onClientEventHeading:(id)heading;
-(void)onClientEventLocationUnavailable:(id)unavailable;
-(void)onClientEventLocation:(id)location;
-(void)onClientEventAuthStatus:(id)status;
-(void)onClientEvent:(int)event supportInfo:(id)info;
-(id)technologiesInUse;
-(id)appsUsingLocationWithDetails;
-(id)appsUsingLocation;
-(void)resetApps;
-(void)stopMonitoringForRegion:(id)region;
-(void)startMonitoringForRegion:(id)region;
-(void)startMonitoringForRegion:(id)region desiredAccuracy:(double)accuracy;
-(void)stopMonitoringSignificantLocationChanges;
-(void)startMonitoringSignificantLocationChanges;
-(void)stopTechStatusUpdates;
-(void)startTechStatusUpdates;
-(void)stopAppStatusUpdates;
-(void)startAppStatusUpdates;
-(void)dismissHeadingCalibrationDisplay;
-(void)stopUpdatingHeading;
-(void)startUpdatingHeading;
-(void)historicLocationsFromDate:(id)date forInterval:(double)interval;
-(void)stopUpdatingLocation;
-(void)startUpdatingLocation;
-(void)dealloc;
-(id)initWithEffectiveBundle:(id)effectiveBundle;
-(id)initWithEffectiveBundleIdentifier:(id)effectiveBundleIdentifier;
-(id)init;
-(id)initWithEffectiveBundleIdentifier:(id)effectiveBundleIdentifier bundle:(id)bundle;
@end

@interface CLLocationManager (CLLocationManagerAuthorization)
+(void)setEntityAuthorized:(BOOL)authorized forLocationDictionary:(id)locationDictionary;
+(BOOL)isEntityAuthorizedForLocationDictionary:(id)locationDictionary;
+(id)dateLocationLastUsedForLocationDictionary:(id)locationDictionary;
+(unsigned)activeLocationServiceTypesForLocationDictionary:(id)locationDictionary;
+(BOOL)isLocationActiveForLocationDictionary:(id)locationDictionary;
+(unsigned)entityClassesForLocationDictionary:(id)locationDictionary;
+(unsigned)primaryEntityClassForLocationDictionary:(id)locationDictionary;
+(BOOL)isStatusBarIconEnabledForLocationEntityClass:(unsigned)locationEntityClass;
+(void)setStatusBarIconEnabled:(BOOL)enabled forLocationEntityClass:(unsigned)locationEntityClass;
@end


