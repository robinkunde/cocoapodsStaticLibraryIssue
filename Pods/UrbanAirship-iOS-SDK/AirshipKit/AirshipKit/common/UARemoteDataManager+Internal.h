/* Copyright 2018 Urban Airship and Contributors */

#import <Foundation/Foundation.h>

@class UADisposable;
@class UARemoteDataPayload;
@class UAPreferenceDataStore;
@class UAConfig;

NS_ASSUME_NONNULL_BEGIN

typedef void (^UARemoteDataPublishBlock)(NSArray<UARemoteDataPayload *> *remoteDataArray);

/**
 * Delegate protocol for receiving callbacks related to
 * Remote Data delivery and display.
 */
@protocol UARemoteDataRefreshDelegate <NSObject>

@optional

///---------------------------------------------------------------------------------------
/// @name Remote Data Refresh Delegate Optional Methods
///---------------------------------------------------------------------------------------

/**
 * Called when a refresh succeeds.
 */
- (void)refreshComplete:(BOOL)success;

@end

@interface UARemoteDataManager : NSObject

///---------------------------------------------------------------------------------------
/// @name Remote Data Manager Client API
///---------------------------------------------------------------------------------------

/**
 * Subscribe to the remote data manager
 *
 * @param payloadTypes You will be notified when there is new remote data for these payload types
 * @param publishBlock The block on which you will be notified when new remote data arrives for your payload types
 *              Note: this block will be called ASAP if there is cached remote data for your payload types
 * @return UADisposable object - call "dispose" on the object to unsubscribe from the remote data manager
 */
- (UADisposable *)subscribeWithTypes:(NSArray<NSString *> *)payloadTypes block:(UARemoteDataPublishBlock)publishBlock;

///---------------------------------------------------------------------------------------
/// @name Properties & Internal Methods
///---------------------------------------------------------------------------------------

/**
 * The delegate that should be notified when each refresh completes.,
 * as an object conforming to the UARemoteDataRefreshDelegate protocol.
 * NOTE: The delegate is not retained.
 */
@property (nonatomic, weak, nullable) id <UARemoteDataRefreshDelegate> refreshDelegate;

/**
 * The minimum amount of time in seconds between remote data refreshes. Increase this
 * value to reduce the frequency of refreshes.
 */
@property (nonatomic, assign) NSUInteger remoteDataRefreshInterval;

/**
 * Refresh the remote data from the cloud
 */
- (void)refresh;

/**
 * Refresh the remote data from the cloud only if the time since the last refresh
 * is greater than the minimum foreground refresh interval.
 */
- (void)foregroundRefresh;

/**
 * Create the remote data manager.
 *
 * @param config The Urban Airship config.
 * @param dataStore A UAPreferenceDataStore to store persistent preferences
 * @return The remote data manager instance.
 */
+ (nonnull instancetype)remoteDataManagerWithConfig:(UAConfig *)config dataStore:(UAPreferenceDataStore *)dataStore;

@end

NS_ASSUME_NONNULL_END
