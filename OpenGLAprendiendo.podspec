Pod::Spec.new do |spec|
  spec.name                  = 'OpenGLAprendiendo'
  spec.version               = '0.0.1'
  spec.summary               = 'OpenGL C++ Triangle class to render a colorful triangle'
  spec.homepage              = 'https://github.com/rbaumbach/OpenGLAprendiendo'
  spec.license               = { :type => 'MIT' }
  spec.author                = { 'Ryan Baumbach' => 'github@ryan.codes' }
  spec.source                = { :git => 'https://github.com/rbaumbach/OpenGLAprendiendo.git', :tag => '0.0.1' }
  spec.osx.deployment_target = '10.13.3'
  spec.ios.deployment_target = '11.2'
  spec.public_header_files   = 'OpenGLAprendiendo/Triangle/*.{hpp}',
                               'OpenGLAprendiendo/Triangle/Shaders/*.{hpp}'
  spec.source_files          = 'OpenGLAprendiendo/Triangle/*.{hpp,cpp}',
                               'OpenGLAprendiendo/Triangle/Shaders/*.{hpp,cpp}'
end
