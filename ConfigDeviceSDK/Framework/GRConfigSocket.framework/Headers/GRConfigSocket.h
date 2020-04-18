//
//  GRConfigSocket.h
//  GRSocketFramework
//
//  Created by world hello on 2017/7/5.
//  Copyright © 2017年 gree. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger ,GRServerType) {
    GRServerTypeOnline = 0,//正式服务
    GRServerTypeTesting,//测试
    GRServerTypeHall,//展厅
    GRServerTypeEurope,//欧洲
};

typedef void(^CompletionHandlerBlock)(NSString * _Nullable name,NSDictionary * _Nullable result);

@interface GRConfigSocket : NSObject

@property (nonatomic,copy)CompletionHandlerBlock _Nullable completionBlock;

+ (instancetype _Nonnull )shareConfigSocket;

/**
 *  start initialization userinfo
 *
 *  @param token    token
 *  @param accessToken   accessToken
 */
- (void)configUserInfoWithToken:(NSString * _Nonnull )token accessToken:(NSString * _Nonnull)accessToken;

/**
 *  start network configuration
 *
 *  @param ssid     router name
 *  @param server   (enum)
 *  @param password router password
 *  @param completionHandlerBlock    completionHandlerBlock
 */
- (void)startConfigSocketWithSSID:(NSString *_Nonnull)ssid
                         Password:(NSString *_Nonnull)password
                     Server:(GRServerType)server
           CompletionHandlerBlock:(CompletionHandlerBlock _Nonnull )completionHandlerBlock;

/**
 * stop configuration
 */
- (void)stopConfigSocket;



@end
