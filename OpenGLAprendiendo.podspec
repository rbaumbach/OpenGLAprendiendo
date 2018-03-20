Pod::Spec.new do |s|
  s.name                  = 'OpenGLAprendiendo'
  s.version               = '0.0.1'
  s.summary               = 'OpenGL C++ Triangle class to render a colorful triangle'
  s.homepage              = 'https://github.com/rbaumbach/OpenGLAprendiendo'
  s.license               = { :type => 'MIT', :file => 'LICENSE' }
  s.author                = { 'Ryan Baumbach' => 'github@ryan.codes' }
  s.source                = { :git => 'https://github.com/rbaumbach/OpenGLAprendiendo.git', :tag => s.version.to_s }
  s.requires_arc          = true
  s.ios.deployment_target = '11.2'
  s.osx.deployment_target = '10.13.3'
  s.public_header_files   = 'OpenGLAprendiendo/Triangle/*.{hpp}',
                            'OpenGLAprendiendo/Triangle/Shaders/*.{hpp}'
  s.source_files          = 'OpenGLAprendiendo/Triangle/*.{hpp,cpp}',
                            'OpenGLAprendiendo/Triangle/Shaders/*.{hpp,cpp}'
  spec.ios.framework      = 'OpenGLES'
  spec.osx.framework      = 'OpenGL'
end
