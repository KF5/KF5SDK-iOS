Pod::Spec.new do |s|
  s.name        = 'KF5SDK'
  s.version     = '1.5.5'
  s.summary     = '逸创云客服SDK嵌入到您原生IOS APP中，集成了工单反馈、反馈列表、文档知识库和即时交谈IM。'
  s.description = '逸创云客服官方SDK，帮助开发者快速完成开发，提供给开发者创建工单、查看工单列表、回复工单、查看和搜索知识库文档、消息通知推送、即时IM等功能。目前支持iOS7.0及以上系统。详细信息请见官网www.kf5.com(为您留住每一个客户,企业信赖的全渠道云客服平台)。'
  s.license     = 'MIT'
  s.authors     = {"KF5"=>"saintye@kf5.com"}
  s.homepage    = 'http://developer.kf5.com/ios'

  s.source      = { :git => "https://github.com/KF5/KF5SDK-iOS.git", :tag => s.version.to_s }
  s.frameworks  = ["Accelerate","JavaScriptCore","CoreTelephony", "SystemConfiguration", "AudioToolbox", "MobileCoreServices", "AssetsLibrary", "AVFoundation", "ImageIO", "CoreGraphics", "Security", "CoreFoundation", "CoreText", "QuartzCore", "UIKit", "Foundation"]
  s.libraries   = 'sqlite3'

  s.platform    = :ios, '7.0'
  s.requires_arc = true

  s.vendored_frameworks = 'KF5SDK/KF5SDK.framework'
  s.vendored_library    = 'KF5SDK/libopencore-amrnb.a'
  s.preserve_path       = 'KF5SDK/libopencore-amrnb.a'
  s.resource            = 'KF5SDK/KF5SDK.bundle'
end
