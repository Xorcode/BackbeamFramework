//
//  Backbeam.h
//  Backbeam
//
//  Created by Alberto Gimeno Brieba on 16/08/12.
//  Copyright (c) 2012 Level Apps S.L. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSDictionary+SanityChecks.h"
#import "Common.h"
#import "BBError.h"
#import "BBQuery.h"
#import "BBObject.h"
#import "BBLocation.h"
#import "BBJoinResult.h"
#import "BBPushNotification.h"
#import "BBTwitterLoginViewController.h"

@class BBQuery;
@class BBTwitterLoginViewController;

@interface BackbeamSession : NSObject

- (void)download:(NSMutableURLRequest*)request
        progress:(ProgressDataBlock)progress
         success:(SuccessDataBlock)success
         failure:(FailureBlock)failure;

- (void)downloadPath:(NSString*)path
            progress:(ProgressDataBlock)progress
             success:(SuccessDataBlock)success
             failure:(FailureBlock)failure;

- (UIImage*)image:(NSString*)identifier
         withSize:(CGSize)size
         progress:(ProgressDataBlock)progress
          success:(SuccessImageBlock)success
          failure:(FailureBlock)failure;

- (void)setLoggedUser:(BBObject*)user;

- (void)persistDeviceToken:(NSData*)data;

- (void)perform:(NSString*)httpMethod
           path:(NSString*)path
         params:(NSDictionary*)params
        success:(SuccessOperationBlock)success
        failure:(FailureOperationBlock)failure;

@end

@interface Backbeam : NSObject

+ (void)setHost:(NSString*)host
           port:(NSInteger)port;

+ (void)setProject:(NSString*)project
         sharedKey:(NSString*)sharedKey
         secretKey:(NSString*)secretKey
       environment:(NSString*)env;

+ (void)setTwitterConsumerKey:(NSString *)twitterConsumerKey
               consumerSecret:(NSString*)twitterConsumerSecret;

+ (BBTwitterLoginViewController*)twitterLoginViewController;

+ (BBQuery*)queryForEntity:(NSString*)entity;

+ (BBObject*)emptyObjectForEntity:(NSString*)entity;

+ (BBObject*)emptyObjectForEntity:(NSString*)entity
                   withIdentifier:(NSString*)identifier;

+ (BOOL)subscribeToChannels:(NSArray*)channels
                    success:(SuccessBlock)success
                    failure:(FailureBlock)failure;

+ (BOOL)subscribeToChannels:(NSArray*)channels;

+ (BOOL)unsubscribeFromChannels:(NSArray*)channels
                        success:(SuccessBlock)success
                        failure:(FailureBlock)failure;
+ (BOOL)unsubscribeFromChannels:(NSArray*)channels;

+ (void)sendPushNotification:(BBPushNotification*)notification
                   toChannel:(NSString*)channel
                     success:(SuccessBlock)success
                     failure:(FailureBlock)failure;

+ (void)sendPushNotification:(BBPushNotification*)notification
                   toChannel:(NSString*)channel;

+ (BBObject*)loggedUser;

+ (void)logout;

+ (void)persistDeviceToken:(NSData*)data;

+ (void)loginWithEmail:(NSString*)email
              password:(NSString*)password
               success:(SuccessObjectBlock)success
               failure:(FailureBlock)failure;

+ (void)requestPasswordResetWithEmail:(NSString*)email
                              success:(SuccessBlock)success
                              failure:(FailureBlock)failure;

@end
