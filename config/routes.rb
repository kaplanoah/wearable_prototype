Wearable::Application.routes.draw do
  
  root to: 'dashboard#main'

  get 'import_values', to: 'dashboard#import_values'

end
