/* Copyright 2018 Urban Airship and Contributors */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UAInAppMessageButtonInfo.h"
#import "UAColorUtils+Internal.h"
#import "UAInAppMessageButtonView+Internal.h"
#import "UAInAppMessageTextView+Internal.h"
#import "UAInAppMessageButton+Internal.h"
#import "UAInAppMessageAdapterProtocol.h"
#import "UAInAppMessageMediaView+Internal.h"
#import "UAInAppMessageCloseButton+Internal.h"

@interface UAInAppMessageUtils : NSObject

/**
 * Applies button info to a button.
 *
 * @param buttonInfo The button info.
 * @param button The button.
 * @param buttonMargin Specify the top and bottom margin between the edge of the button and the edge of the label
 */
+ (void)applyButtonInfo:(UAInAppMessageButtonInfo *)buttonInfo button:(UAInAppMessageButton *)button buttonMargin:(CGFloat)buttonMargin;

/**
 * Applies text info to a text label.
 *
 * @param textInfo The text info.
 * @param label The label.
 */
+ (void)applyTextInfo:(UAInAppMessageTextInfo *)textInfo label:(UILabel *)label;

/**
 * Constrains the contained view to the center of the container with equivalent size
 *
 * This method has the side effect of setting both views' translatesAutoresizingMasksIntoConstraints parameters to NO.
 * This is done to ensure that autoresizing mask constraints do not conflict with the centering constraints.
 * 
 * @param container The container view.
 * @param contained The contained view.
 */
+ (void)applyContainerConstraintsToContainer:(UIView *)container containedView:(UIView *)contained;

/**
 * Constrains the contained view to the center of the container
 *
 * This method has the side effect of setting both views' translatesAutoresizingMasksIntoConstraints parameters to NO.
 * This is done to ensure that autoresizing mask constraints do not conflict with the centering constraints.
 *
 * @param container The container view.
 * @param contained The contained view.
 */
+ (void)applyCenterConstraintsToContainer:(UIView *)container containedView:(UIView *)contained;

/**
 * Constrains the close button view to the upper right of the container
 *
 * This method has the side effect of setting both views' translatesAutoresizingMasksIntoConstraints parameters to NO.
 * This is done to ensure that autoresizing mask constraints do not conflict with the close button constraints.
 *
 * @param container The container view.
 * @param closeButton The contained close button.
 */
+ (void)applyCloseButtonConstraintsToContainer:(UIView *)container closeButton:(UAInAppMessageCloseButton *)closeButton;

/**
 * Caches url data contents using a background thread. Calls completion handler on main thread
 * with cache key under which the cached contents are stored.
 *
 * @param url The url of the data contents you wish to cache.
 * @param cache The cache instance.
 * @param completionHandler The completion handler with cache key for pulling conents out of cache, and a result status.
 */
+ (void)prefetchContentsOfURL:(NSURL *)url WithCache:(NSCache *)cache completionHandler:(void (^)(NSString *cacheKey, UAInAppMessagePrepareResult result))completionHandler;

/**
 * Runs actions for a button.
 *
 * @param button The button.
 */
+ (void)runActionsForButton:(UAInAppMessageButton *)button;

/**
 * Creates an NSCache for the adapter's media.
 *
 * @return The NSCache
 */
+ (NSCache *)createImageCache;

/**
 * Prepares in-app message to display.
 *
 * @param media media info object for this message
 * @param imageCache the cache for images
 * @param completionHandler the completion handler to be called when media is ready.
 */
+ (void)prepareMediaView:(UAInAppMessageMediaInfo *)media imageCache:(NSCache *)imageCache completionHandler:(void (^)(UAInAppMessagePrepareResult, UAInAppMessageMediaView *))completionHandler;

/**
 * Informs the adapter of the ready state of the in-app message immediately before display.
 *
 * @param media media info object for this message
 * @return `YES` if the in-app message is ready, `NO` otherwise.
 */
+ (BOOL)isReadyToDisplayWithMedia:(UAInAppMessageMediaInfo *)media;

@end
